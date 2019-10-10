/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:35:04 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/10 13:25:25 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int argc, char ** argv)
{
	int	rev;

	ft_printf("FT_PRINTF\n");
	rev = ft_printf("test %007d%-10.2ls!!", 0x45, L"〻");
	ft_printf("return value = %d\n", rev);
	ft_printf("PRINTF\n");
	rev = printf("test %007d%-10.2ls!!", 0x45, L"〻");
	printf("return value = %d\n", rev);
	return (0);
}
