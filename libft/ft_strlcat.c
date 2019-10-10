/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 23:41:28 by ferdinand         #+#    #+#             */
/*   Updated: 2019/04/05 15:16:01 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len_d;
	size_t i;

	len_d = 0;
	i = 0;
	while (dest[len_d] && len_d < size)
		len_d++;
	while (i + 1 + len_d < size && src[i])
	{
		dest[len_d + i] = src[i];
		i++;
	}
	if (len_d != size)
		dest[len_d + i] = 0;
	return (len_d + ft_strlen(src));
}
