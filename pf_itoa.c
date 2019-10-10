/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:08:30 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/05 16:32:19 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_nb_str(long long n, char *str, int size_nb, t_pflist *list)
{
	int sign;

	sign = 0;
	if (n == -9223372036854775807 - 1)
	{
		str[--size_nb] = '8';
		n = -922337203685477580;
	}
	if (list->sign)
	{
		str[0] = list->sign;
		sign++;
		n = n < 0 ? -n : n;
	}
	while (size_nb-- > sign)
	{
		str[size_nb] = n % 10 + '0';
		n = n / 10;
	}
}

char			*pf_itoa(va_list ap, t_pflist *list)
{
	int		size_nb;
	int		size_tot;
	char	*result;
	long	arg;

	arg = g_get_arg_tab[list->type](ap).ll;
	size_nb = get_size_nb(arg);
	list->sign = get_sign(arg, list);
	if ((list->param << FPREC) & MASK)
		size_nb = check_precision(arg, list, size_nb);
	else
		size_nb = check_fzero(list, size_nb);
	size_tot = size_nb + (list->sign ? 1 : 0);
	if (!(result = ft_strnew(size_tot)))
		return (NULL);
	fill_nb_str(arg, result, size_tot, list);
	if ((list->param << FWIDTH) & MASK && list->field_width > size_tot)
		if (!(result = ft_strjoin_free_order(result,
						width_str(list->field_width - size_tot, ' '), 1,
					!((list->param << FMINUS) & MASK))))
			return (NULL);
	return (result);
}
