/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubletoa2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:16:13 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/06 18:30:13 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_all_double_str(t_pflist *list)
{
	list->double_param.buff_ent ? free(list->double_param.buff_ent) : 0;
	list->double_param.result_ent ? free(list->double_param.result_ent) : 0;
	list->double_param.buff_dec ? free(list->double_param.buff_dec) : 0;
	list->double_param.result_dec ? free(list->double_param.result_dec) : 0;
	list->double_param.mantissa ? free(list->double_param.mantissa) : 0;
}

char	*get_width_space_str(char *result, int len, t_pflist *list)
{
	char	*space_str;

	if (!(space_str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		ft_memdel((void **)&result);
		return (NULL);
	}
	space_str[len] = '\0';
	while (--len >= 0)
		space_str[len] = ' ';
	if (!(result = ft_strjoin_free_order(result, space_str, 1,
			!((list->param << FMINUS) & MASK))))
		return (NULL);
	return (result);
}

void	get_exponent_and_sign(long double arg, t_pflist *list)
{
	uint8_t *ptr;

	ptr = (uint8_t *)&arg;
	list->double_param.exp = (*(uint16_t *)(ptr + 8) & MASKEXP) - 16383;
	list->double_param.sign = (*(uint16_t *)(ptr + 8) & MASKSIGN) ?
		1 : 0;
}

char	*get_mantissa(long double arg, int size)
{
	int		i;
	int		j;
	char	*mantissa;
	uint8_t	*byteptr;
	uint8_t	byte;

	i = 0;
	j = 0;
	byteptr = (uint8_t *)&arg;
	if (!(mantissa = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	mantissa[size] = '\0';
	while (i < 8)
	{
		byte = byteptr[i];
		while (j++ < 8)
		{
			mantissa[--size] = (byte & 1) + '0';
			byte >>= 1;
		}
		j = 0;
		i++;
	}
	return (mantissa);
}

char	*pf_doubletoa(va_list ap, t_pflist *list)
{
	char		*result;
	long double	arg;

	double_str_to_null(list->double_param);
	arg = g_get_arg_tab[list->type](ap).ld;
	get_exponent_and_sign(arg, list);
	if (!(list->double_param.mantissa = get_mantissa(arg, 64)))
		return (NULL);
	if (list->double_param.exp == 16384)
	{
		free(list->double_param.mantissa);
		return (double_exception(list->double_param.mantissa, list));
	}
	if (!(init_double_str(list)))
	{
		free_all_double_str(list);
		return (NULL);
	}
	check_for_operation(list);
	result = get_final_str(list);
	free_all_double_str(list);
	return (result);
}
