/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:51:41 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/05/21 17:04:59 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_test	get_arg_int(va_list ap)
{
	t_test test;

	test.ll = va_arg(ap, int);
	return (test);
}

t_test	get_arg_char(va_list ap)
{
	t_test test;

	test.ll = (char)va_arg(ap, int);
	return (test);
}

t_test	get_arg_short(va_list ap)
{
	t_test test;

	test.ll = (short)va_arg(ap, int);
	return (test);
}

t_test	get_arg_long(va_list ap)
{
	t_test test;

	test.ll = va_arg(ap, long);
	return (test);
}

t_test	get_arg_longlong(va_list ap)
{
	t_test test;

	test.ll = va_arg(ap, long long);
	return (test);
}
