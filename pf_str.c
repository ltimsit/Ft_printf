/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:53:10 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/05 16:34:23 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_str(va_list ap, t_pflist *list)
{
	char	*result;
	int		len;
	char	*str;

	str = g_get_arg_tab[list->type](ap).str;
	len = str ? ft_strlen(str) : 6;
	if (((list->param << FPREC) & MASK) && list->field_precision < len)
		len = list->field_precision;
	if (str && !(result = ft_strndup(str, len)))
		return (NULL);
	if (!str && !(result = ft_strndup("(null)", len)))
		return (NULL);
	if ((list->param << FWIDTH) & MASK && list->field_width > len)
		if (!(result = ft_strjoin_free_order(result,
			width_str(list->field_width - len, (list->param << FZERO) & MASK ?
				'0' : ' '), 1, !((list->param << FMINUS) & MASK))))
			return (NULL);
	return (result);
}
