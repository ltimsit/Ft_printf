/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:13:27 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/08 13:11:34 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_type2(t_pflist *list)
{
	if (list->conv_id == '%')
		list->type = tpercent;
	else if (list->conv_id == 'b')
		list->type = tbint + list->hh + list->h + list->l + list->ll
			+ (list->upl ? 5 : 0);
	else if (list->conv_id == 'U' || list->conv_id == 'O')
		list->type = tunsignedlong;
	else if (list->conv_id == 'D')
		list->type = tlong;
	else
		list->type = tcharchar;
}

void		get_type(t_pflist *list)
{
	if (list->conv_id == 'd' || list->conv_id == 'i')
		list->type = tint + list->hh + list->h + list->l + list->ll;
	else if (list->conv_id == 'u')
		list->type = tunsignedint + list->hh + list->h + list->l + list->ll;
	else if (list->conv_id == 'o' || list->conv_id == 'x' ||
			list->conv_id == 'X')
		list->type = tunsignedint + list->hh + list->h + list->l + list->ll;
	else if (list->conv_id == 'p')
		list->type = tunsignedlong;
	else if (list->conv_id == 's')
		list->type = tcharptr;
	else if (list->conv_id == 'c')
		list->type = tcharchar;
	else if (list->conv_id == 'f' || list->conv_id == 'F')
		list->type = tdouble + list->upl;
	else
		get_type2(list);
}
