/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubletoa_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:16:58 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/07 10:59:58 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_double_new(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (i < size)
		str[i++] = '0';
	return (str);
}

int		init_double_str(t_pflist *list)
{
	if (!(list->double_param.result_ent =
		str_double_new(list->double_param.exp >= 0
			? (list->double_param.exp / 3 + 1) : 1)) ||
	!(list->double_param.buff_ent =
		str_double_new(list->double_param.exp >= 0
			? (list->double_param.exp / 3 + 1) : 1)) ||
	!(list->double_param.result_dec = str_double_new(list->double_param.exp < 0
			? -list->double_param.exp + 64 : 50)) ||
	!(list->double_param.buff_dec = str_double_new(list->double_param.exp < 0
			? -list->double_param.exp + 64 : 50)))
		return (0);
	list->double_param.buff_dec[0] = '1';
	list->double_param.buff_ent[list->double_param.exp / 3] = '1';
	return (1);
}

void	check_for_mult(char *result_ent, char *buff_ent, char *mantissa, int i)
{
	int j;

	j = 0;
	if (i > 63)
	{
		j = i - 63;
		i = 63;
	}
	while (i >= 0)
	{
		if (mantissa[i] == '1')
		{
			get_mult_by_exp(result_ent, buff_ent, j);
			j = 0;
		}
		j++;
		i--;
	}
}

void	check_for_div(char *result_dec, char *buff_dec, char *mantissa, int i)
{
	int j;

	j = 1;
	if (i < 0)
	{
		j = -i;
		i = 0;
	}
	while (mantissa[i] && i < 64)
	{
		if (mantissa[i] == '1')
		{
			get_div_by_exp(result_dec, buff_dec, j);
			j = 0;
		}
		j++;
		i++;
	}
}

void	check_for_operation(t_pflist *list)
{
	int i;

	i = list->double_param.exp;
	check_for_mult(list->double_param.result_ent, list->double_param.buff_ent,
			list->double_param.mantissa, i);
	check_for_div(list->double_param.result_dec, list->double_param.buff_dec,
			list->double_param.mantissa, i >= 0 ? i + 1 : i);
}
