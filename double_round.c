/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:33:22 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/07 11:48:36 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_d(char *decimal, int i)
{
	while (decimal[++i])
	{
		if (decimal[i] != '0')
			return (0);
	}
	return (1);
}

void	double_round(char *d_decimal, char *decimal, int i, int check)
{
	if (d_decimal[i] > '5' || (d_decimal[i] == '5' && !check))
	{
		decimal[--i] += 1;
		while (decimal[i] > '9')
		{
			decimal[i] -= 10;
			decimal[--i] += 1;
		}
	}
	if (d_decimal[i] == '5' && check && (d_decimal[i - 1] % 2 == 1 ||
				d_decimal[i - 1] == '.'))
	{
		if (d_decimal[i - 1] == '.')
			decimal[--i] = '-';
		else
		{
			decimal[--i] += 1;
			while (decimal[i] > '9')
			{
				decimal[i] -= 10;
				decimal[--i] += 1;
			}
		}
	}
}
