/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_g_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:38:46 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/05 14:08:52 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fct_tab2(void)
{
	g_fct_tab[0] = pf_itoa;
	g_fct_tab[1] = pf_itoa;
	g_fct_tab[2] = pf_itoa;
	g_fct_tab[3] = pf_itoa;
	g_fct_tab[4] = pf_itoa;
	g_fct_tab[5] = pf_utoabase;
	g_fct_tab[6] = pf_utoabase;
	g_fct_tab[7] = pf_utoabase;
	g_fct_tab[8] = pf_utoabase;
	g_fct_tab[9] = pf_utoabase;
	g_fct_tab[10] = pf_str;
	g_fct_tab[11] = pf_char;
	g_fct_tab[12] = pf_doubletoa;
	g_fct_tab[13] = pf_doubletoa;
	g_fct_tab[14] = pf_binary;
	g_fct_tab[15] = pf_binary;
	g_fct_tab[16] = pf_binary;
	g_fct_tab[17] = pf_binary;
	g_fct_tab[18] = pf_binary;
	g_fct_tab[19] = pf_binary;
	g_fct_tab[20] = pf_percent;
}

void	init_fct_tabs(void)
{
	g_get_arg_tab[0] = get_arg_int;
	g_get_arg_tab[1] = get_arg_char;
	g_get_arg_tab[2] = get_arg_short;
	g_get_arg_tab[3] = get_arg_long;
	g_get_arg_tab[4] = get_arg_longlong;
	g_get_arg_tab[5] = get_arg_unsignedint;
	g_get_arg_tab[6] = get_arg_unsignedchar;
	g_get_arg_tab[7] = get_arg_unsignedshort;
	g_get_arg_tab[8] = get_arg_unsignedlong;
	g_get_arg_tab[9] = get_arg_unsignedlonglong;
	g_get_arg_tab[10] = get_arg_strptr;
	g_get_arg_tab[11] = get_arg_char;
	g_get_arg_tab[12] = get_arg_double;
	g_get_arg_tab[13] = get_arg_longdouble;
	g_get_arg_tab[14] = get_arg_int;
	g_get_arg_tab[15] = get_arg_char;
	g_get_arg_tab[16] = get_arg_short;
	g_get_arg_tab[17] = get_arg_long;
	g_get_arg_tab[18] = get_arg_longlong;
	g_get_arg_tab[19] = get_arg_longdouble;
	init_fct_tab2();
}
