/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:28:30 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/02 15:44:05 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin_free_order(const char *s1, const char *s2,
					int free_nb, int order)
{
	char	*str;
	size_t	ss1;
	size_t	ss2;

	str = NULL;
	if (s1 && s2)
	{
		ss1 = ft_strlen(s1);
		ss2 = ft_strlen(s2);
		str = ft_strnew(ss1 + ss2);
		order == 0 && str ? ft_strcat(str, s1) : ft_strcat(str, s2);
		order == 0 && str ? ft_strcat(str, s2) : ft_strcat(str, s1);
	}
	if (free_nb == 1 && s1 && s2)
	{
		ft_memdel((void **)&s1);
		ft_memdel((void **)&s2);
	}
	if (free_nb == 2 && s1)
		ft_memdel((void **)&s1);
	if (free_nb == 3 && s2)
		ft_memdel((void **)&s2);
	return (str);
}
