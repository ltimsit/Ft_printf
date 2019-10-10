/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:58:05 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/02 22:38:30 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	n_abs;

	if (!(str = ft_strnew(10)))
		return (NULL);
	n_abs = n < 0 ? -n : n;
	i = 0;
	if (n_abs == 0)
		str[i++] = '0';
	while (n_abs != 0)
	{
		str[i] = n_abs % 10 + 48;
		n_abs /= 10;
		i++;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
