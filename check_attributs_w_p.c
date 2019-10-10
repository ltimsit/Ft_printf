/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_attributs_w_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:10:35 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/09 15:35:41 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_prec(char *str, t_pflist *list, int i, va_list ap)
{
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*')
			list->field_precision = va_arg(ap, int);
		else
			list->field_precision = ft_atoi(str + i);
		if (list->field_precision >= 0)
			list->param ^= MASK >> FPREC;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
		i++;
	return (i);
}

int			check_fw_prec(char *str, t_pflist *list, int i, va_list ap)
{
	if ((str[i] > '0' && str[i] <= '9') || str[i] == '*')
	{
		if (str[i] == '*')
			list->field_width = va_arg(ap, int);
		else
			list->field_width = ft_atoi(str + i);
		if (list->field_width > 0)
			list->param ^= MASK >> FWIDTH;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
		i++;
	return (check_prec(str, list, i, ap));
}

void		overwrite_flag(t_pflist *list)
{
	if ((list->param << FPLUS) & MASK)
		list->param &= MASKSPACE;
	if ((list->param << FMINUS) & MASK)
		list->param &= MASKZERO;
}

int			check_attributs(char *str, t_pflist *list)
{
	int i;

	i = 1;
	while (str[i] == '#' || str[i] == '0' || str[i] == '-'
			|| str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '#')
			list->param |= MASK >> FHASH;
		if (str[i] == '0')
			list->param |= MASK >> FZERO;
		if (str[i] == '-')
			list->param |= MASK >> FMINUS;
		if (str[i] == ' ')
			list->param |= MASK >> FSPACE;
		if (str[i++] == '+')
			list->param |= MASK >> FPLUS;
	}
	overwrite_flag(list);
	return (i);
}
