/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 03:23:04 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/02 22:59:14 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int n_abs;
	unsigned int i;

	i = 1000000000;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	n_abs = n < 0 ? -n : n;
	if (n < 0)
		ft_putchar('-');
	while (i != 0)
	{
		if (i <= n_abs)
			ft_putchar(n_abs / i % 10 + 48);
		i /= 10;
	}
}
