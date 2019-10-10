/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_fct3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:51:00 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/07 14:49:09 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_test	get_arg_strptr(va_list ap)
{
	t_test test;

	test.str = va_arg(ap, char *);
	return (test);
}

t_test	get_arg_double(va_list ap)
{
	t_test test;

	test.ld = va_arg(ap, double);
	return (test);
}

t_test	get_arg_longdouble(va_list ap)
{
	t_test test;

	test.ld = (long double)va_arg(ap, long double);
	return (test);
}
