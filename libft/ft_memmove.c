/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 23:41:05 by ferdinand         #+#    #+#             */
/*   Updated: 2019/04/06 17:40:52 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	if ((unsigned long)dest < (unsigned long)src)
		return (ft_memcpy(dest, src, n));
	else
	{
		src1 = (unsigned char *)src;
		dest1 = (unsigned char *)dest;
		while (n--)
			dest1[n] = src1[n];
		return (dest1);
	}
}
