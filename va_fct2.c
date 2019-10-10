/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_fct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:47:39 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/05/19 14:34:57 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_test	get_arg_unsignedint(va_list ap)
{
	t_test test;

	test.ul = va_arg(ap, unsigned int);
	return (test);
}

t_test	get_arg_unsignedchar(va_list ap)
{
	t_test test;

	test.ul = (unsigned char)va_arg(ap, unsigned int);
	return (test);
}

t_test	get_arg_unsignedshort(va_list ap)
{
	t_test test;

	test.ul = (unsigned short)va_arg(ap, unsigned int);
	return (test);
}

t_test	get_arg_unsignedlong(va_list ap)
{
	t_test test;

	test.ul = va_arg(ap, unsigned long);
	return (test);
}

t_test	get_arg_unsignedlonglong(va_list ap)
{
	t_test test;

	test.ull = va_arg(ap, unsigned long long);
	return (test);
}
