/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 03:35:42 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/02 22:59:23 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n_abs;
	unsigned int i;

	i = 1000000000;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	n_abs = n < 0 ? -n : n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (i != 0)
	{
		if (i <= n_abs)
			ft_putchar_fd(n_abs / i % 10 + 48, fd);
		i /= 10;
	}
}
