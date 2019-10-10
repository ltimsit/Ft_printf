/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:57:47 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/05 16:28:59 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_str(int size_width, char c)
{
	char	*widthstr;
	int		i;

	i = 0;
	if (!(widthstr = ft_strnew(size_width)))
		return (NULL);
	while (i < size_width)
		widthstr[i++] = c;
	return (widthstr);
}

int		check_fzero(t_pflist *list, int size_nb)
{
	int size_nb_sign;
	int size_sign;

	size_sign = list->sign ? 1 : 0;
	size_nb_sign = size_nb + size_sign;
	if (((list->param << FZERO) & MASK)
			&& ((list->param << FWIDTH) & MASK))
		return (list->field_width > size_nb_sign ?
				list->field_width - size_sign : size_nb);
	else
		return (size_nb);
}

int		check_precision(long long arg, t_pflist *list, int size_nb)
{
	if (((list->param << FPREC) & MASK))
	{
		if (list->field_precision == 0 && arg == 0)
			return (0);
		return (list->field_precision > size_nb ? list->field_precision :
				size_nb);
	}
	return (size_nb);
}

int		get_size_nb(long long arg)
{
	int size;

	size = 1;
	if (arg == -9223372036854775807 - 1)
	{
		arg = -922337203685477580;
		size++;
	}
	arg = arg < 0 ? -arg : arg;
	while (arg >= 10)
	{
		size++;
		arg = arg / 10;
	}
	return (size);
}

char	get_sign(long long arg, t_pflist *list)
{
	if (arg < 0)
		return ('-');
	else if ((list->param << FPLUS) & MASK)
		return ('+');
	else if ((list->param << FSPACE) & MASK)
		return (' ');
	return (0);
}
