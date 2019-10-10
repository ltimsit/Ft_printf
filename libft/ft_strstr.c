/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:34:52 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 15:19:10 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		j = 0;
		i++;
	}
	return (0);
}
