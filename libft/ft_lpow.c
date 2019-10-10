/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:44:44 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 16:52:02 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_lpow(long nb, long power)
{
	long result;

	result = 1L;
	while (power--)
		result *= nb;
	return (result);
}
