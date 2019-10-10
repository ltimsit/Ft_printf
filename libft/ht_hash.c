/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:30:18 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 16:52:14 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ht_hash(const char *str, const int p, const int m)
{
	long	hash;
	int		i;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i] * ft_lpow(p, i);
		i++;
	}
	hash = hash % m;
	return ((int)hash);
}
