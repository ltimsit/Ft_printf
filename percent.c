/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:47:43 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/06 15:07:11 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zero_str(int size)
{
	char	*zerostr;
	int		i;

	i = 0;
	if (!(zerostr = ft_strnew(size)))
		return (NULL);
	while (i < size)
		zerostr[i++] = '0';
	return (zerostr);
}

char	*pf_percent(va_list ap, t_pflist *list)
{
	int		size_width;
	char	*result;

	(void)ap;
	size_width = 0;
	if (((list->param << FWIDTH) & MASK))
		size_width = list->field_width > 1 ? list->field_width - 1 : 0;
	result = ft_strdup("%");
	if (size_width)
	{
		if (((list->param << FZERO) & MASK) &&
				!((list->param << FMINUS) & MASK))
		{
			if (!(result = ft_strjoin_free_order(result, zero_str(size_width),
							1, 1)))
				return (NULL);
		}
		else if (!(result = ft_strjoin_free_order(result,
					width_str(size_width, ' '),
					1, !((list->param << FMINUS) & MASK))))
			return (NULL);
	}
	return (result);
}
