/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubletoa_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:09:04 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/07 10:50:54 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	double_str_to_null(t_double_params param)
{
	param.result_ent = NULL;
	param.result_dec = NULL;
	param.buff_ent = NULL;
	param.buff_dec = NULL;
	param.mantissa = NULL;
}

void	add_buff_to_result(char *dest, char *source, int correc)
{
	int i;

	i = 0;
	while (dest[i])
	{
		dest[i] += correc ? source[i] - '0' : 0;
		i++;
	}
	dest[i - 1] += correc ? 0 : 1;
	while (--i >= 0)
	{
		if (dest[i] > '9')
		{
			dest[i] -= 10;
			dest[i - 1] += 1;
		}
	}
}

void	get_mult_by_exp(char *result, char *buff, int j)
{
	int i;

	while (j--)
	{
		i = 0;
		while (buff[i])
		{
			if (buff[i] != '0')
			{
				buff[i] += (buff[i] - '0');
			}
			i++;
		}
		while (--i >= 0)
		{
			if (buff[i] > '9')
			{
				buff[i] -= 10;
				buff[i - 1] += 1;
			}
		}
	}
	add_buff_to_result(result, buff, 1);
}

void	get_div_by_exp(char *result, char *buff, int j)
{
	int i;
	int rest;

	rest = 0;
	i = 0;
	while (j--)
	{
		while (buff[i])
		{
			if (buff[i] != '0')
			{
				rest = (buff[i] - '0') % 2;
				buff[i] = (buff[i] - '0') / 2 + '0';
				if (buff[i + 1])
					buff[i + 1] += rest * 10;
				else
					buff[i]++;
			}
			i++;
		}
		i = 0;
	}
	add_buff_to_result(result, buff, 1);
}
