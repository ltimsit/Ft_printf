/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:47:53 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/05 16:36:47 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_char(va_list ap, t_pflist *list)
{
	int		size_width;
	char	*result;
	char	arg;

	size_width = 0;
	if (list->conv_id == 'c')
		arg = g_get_arg_tab[list->type](ap).c;
	else
		arg = list->conv_id;
	arg = arg == '\0' ? -1 : arg;
	if (((list->param << FWIDTH) & MASK))
		size_width = list->field_width - 1 > size_width ?
			list->field_width - 1 : size_width;
	if (!(result = ft_strnew(1)))
		return (NULL);
	result[0] = arg;
	if (size_width)
		if (!(result = ft_strjoin_free_order(result,
			width_str(size_width, (list->param << FZERO) & MASK ? '0' : ' '),
			1, !((list->param << FMINUS) & MASK))))
			return (NULL);
	return (result);
}
