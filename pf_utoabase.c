/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:36:44 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/06 19:14:57 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_size_unbbase(unsigned long arg, t_pflist *list)
{
	int size;

	size = 1;
	if (arg == 0 && ((list->param << FPREC) & MASK) &&
			list->field_precision == 0 && !(list->conv_id == 'o' &&
				(list->param << FHASH) & MASK))
		size = 0;
	while (arg >= list->base_nb)
	{
		size++;
		arg = arg / list->base_nb;
	}
	return (size);
}

static void		fill_unbbase_str(unsigned long n, char *str, int size,
					t_pflist *list)
{
	char	*basex;
	char	*baseupx;
	int		i;

	i = 0;
	basex = "0123456789abcdef";
	baseupx = "0123456789ABCDEF";
	if (size || list->conv_id == 'p')
	{
		if ((((list->param << FHASH) & MASK) && list->base_nb != 10) ||
				list->conv_id == 'p')
		{
			str[i++] = '0';
			if ((list->conv_id == 'x') || (list->conv_id == 'p'))
				str[i++] = 'x';
			if (list->conv_id == 'X')
				str[i++] = 'X';
		}
		while (size-- > i)
		{
			str[size] = list->conv_id == 'X' ? baseupx[n % list->base_nb] :
				basex[n % list->base_nb];
			n = n / list->base_nb;
		}
	}
}

int				get_sizehash(t_pflist *list, unsigned long arg)
{
	int size_hash;

	if (list->conv_id != 'p' && arg == 0)
	{
		list->param &= MASKHASH;
		return (0);
	}
	size_hash = 0;
	if (((list->param << FHASH) & MASK && list->base_nb != 10) ||
		(list->conv_id == 'p'))
		size_hash += list->conv_id == 'o' ? 1 : 2;
	return (size_hash);
}

void			check_precision_or_zero(int *size, int *size_space,
					int size_hash, t_pflist *list)
{
	int offset;

	*size_space = 0;
	offset = (list->conv_id == 'o' && ((list->param << FHASH) & MASK) ? 1 : 0);
	if (((list->param << FPREC) & MASK))
	{
		list->param &= MASKZERO;
		*size = list->field_precision > *size + offset ?
			list->field_precision - offset : *size;
	}
	if (((list->param << FZERO) & MASK) && ((list->param << FWIDTH) & MASK)
			&& list->field_width > *size + size_hash)
	{
		*size = list->field_width - size_hash;
	}
	else if ((list->param << FWIDTH) & MASK)
		if ((*size_space = (list->field_width - *size - size_hash)) < 0)
			*size_space = 0;
}

char			*pf_utoabase(va_list ap, t_pflist *list)
{
	int				sn;
	char			*result;
	int				size_hash;
	int				size_space;
	unsigned long	arg;

	arg = g_get_arg_tab[list->type](ap).ul;
	sn = get_size_unbbase(arg, list);
	size_hash = 0;
	size_space = 0;
	if (sn || list->conv_id == 'p')
		size_hash = get_sizehash(list, arg);
	if (sn)
		check_precision_or_zero(&sn, &size_space, size_hash, list);
	else if ((list->param << FWIDTH) & MASK)
		size_space = list->field_width;
	if (!(result = ft_strnew(sn + size_hash)))
		return (NULL);
	fill_unbbase_str(arg, result, sn + size_hash, list);
	if (size_space > 0)
		if (!(result = ft_strjoin_free_order(result,
						width_str(size_space, ' '), 1,
						!((list->param << FMINUS) & MASK))))
			return (NULL);
	return (result);
}
