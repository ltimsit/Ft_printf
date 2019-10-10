/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:47:47 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/09 13:13:49 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_color_tab(char **tab_c)
{
	tab_c[0] = RST;
	tab_c[1] = RED;
	tab_c[2] = GRN;
	tab_c[3] = YEL;
	tab_c[4] = BLU;
	tab_c[5] = MAG;
	tab_c[6] = CYN;
	tab_c[7] = WHT;
	tab_c[8] = "";
}

char	*apply_color(t_pflist *list)
{
	char *tab_c[9];

	init_color_tab(tab_c);
	if (list->conv_id == '{')
		return (ft_strdup("{"));
	return (ft_strdup(tab_c[(int)list->conv_id - 1]));
}
