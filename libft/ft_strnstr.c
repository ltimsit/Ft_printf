/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:43:53 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 15:18:02 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		while (haystack[i + j] == needle[j] && needle[j] && i + j < n)
			j++;
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		i++;
		j = 0;
	}
	return (0);
}
