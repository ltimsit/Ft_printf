/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:22:56 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/08 13:10:30 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_sizeof(t_pflist *list)
{
	int size;

	size = 0;
	if (list->type == 14)
		size = sizeof(int);
	if (list->type == 15)
		size = sizeof(char);
	if (list->type == 16)
		size = sizeof(short);
	if (list->type == 17)
		size = sizeof(long);
	if (list->type == 18)
		size = sizeof(long long);
	if (list->type == 19)
		size = 10;
	return (size);
}

char		*get_b_str(long double arg, int size, int size_tot, t_pflist *list)
{
	int		i;
	int		j;
	char	*b_str;
	int8_t	*byteptr;
	int8_t	byte;

	i = 0;
	j = 0;
	byteptr = (int8_t *)&arg;
	if (!(b_str = (char *)malloc(sizeof(char) * (size_tot + 1))))
		return (NULL);
	b_str[size_tot] = '\0';
	while (i < size)
	{
		byte = byteptr[i++];
		while (j++ < 8)
		{
			b_str[--size_tot] = (byte & 1) + '0';
			byte >>= 1;
		}
		if ((list->param << FSPACE) & MASK && size_tot)
			b_str[--size_tot] = ' ';
		j = 0;
	}
	return (b_str);
}

char		*pf_binary(va_list ap, t_pflist *list)
{
	t_test	arg;
	int		size;
	int		size_tot;

	arg = g_get_arg_tab[list->type](ap);
	size = get_sizeof(list);
	if ((list->param << FSPACE) & MASK)
		size_tot = size * 9 - 1;
	else
		size_tot = size * 8;
	return (get_b_str(arg.ld, size, size_tot, list));
}
