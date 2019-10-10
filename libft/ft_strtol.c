/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:31:32 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 15:19:40 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

long	ft_strtol(const char *str)
{
	int				i;
	int				sign;
	unsigned long	tol;
	unsigned long	cutoff;
	int				cutlim;

	i = 0;
	sign = 1;
	tol = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = 44 - str[i++];
	cutoff = sign == -1 ? LONG_MIN : LONG_MAX;
	cutlim = cutoff % 10;
	cutoff = ABS(cutoff / 10);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (tol > cutoff || (tol == cutoff && str[i] - 48 > cutlim))
			return (10 * cutoff + cutlim);
		tol = tol * 10 + str[i] - 48;
		i++;
	}
	return ((long)tol * sign);
}
