/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 02:14:55 by ferdinand         #+#    #+#             */
/*   Updated: 2019/04/05 15:05:29 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (src1[i] == (unsigned char)c)
		{
			dest1[i] = src1[i];
			return ((unsigned char *)dest + i + 1);
		}
		dest1[i] = src1[i];
		i++;
	}
	return (0);
}
