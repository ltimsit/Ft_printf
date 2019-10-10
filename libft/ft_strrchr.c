/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:42:41 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 15:18:37 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = 0;
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		s++;
	}
	if (*s == c)
		ret = (char *)s;
	return (ret);
}