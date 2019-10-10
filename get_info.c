/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:11:07 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/09 13:15:15 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_length_field(char *str, t_pflist *list, int i)
{
	int j;

	j = 0;
	if ((list->hh = str[i] == 'h' && str[i + 1] == 'h' ? 1 : 0) != 0)
		j += 2;
	if ((list->h = str[i] == 'h' && str[i + 1] != 'h' ? 2 : 0) != 0)
		j += 1;
	if ((list->l = str[i] == 'l' && str[i + 1] != 'l' ? 3 : 0) != 0)
		j += 1;
	if ((list->ll = str[i] == 'l' && str[i + 1] == 'l' ? 4 : 0) != 0)
		j += 2;
	if ((list->upl = str[i] == 'L' ? 1 : 0) != 0)
		j += 1;
	return (i + j);
}

int			get_color(char *str, int i)
{
	int		j;
	char	*tab[8];

	tab[0] = "{RESET}";
	tab[1] = "{RED}";
	tab[2] = "{GREEN}";
	tab[3] = "{YELLOW}";
	tab[4] = "{BLUE}";
	tab[5] = "{MAGENTA}";
	tab[6] = "{CYAN}";
	tab[7] = "{WHITE}";
	j = 0;
	while (j < 8 && ft_strncmp(str, tab[j], i))
		j++;
	return (j + 1);
}

t_pflist	check_color(char *str)
{
	int			i;
	int			color;
	t_pflist	list;

	list.param = 0;
	list.size = 0;
	color = 0;
	i = 1;
	while (str[i] && str[i] != '}' && str[i] != '{' && str[i] != '%')
		i++;
	color = str[i] == '}' ? get_color(str, i) : 9;
	list.size = str[i] && str[i] != '%' ? i : i - 1;
	list.conv_id = str[i] != '{' ? color : '{';
	return (list);
}

t_pflist	check_arg(char *str, va_list ap)
{
	int			i;
	int			j;
	t_pflist	list;

	list.param = 0;
	list.size = 0;
	i = check_attributs(str, &list);
	i = check_fw_prec(str, &list, i, ap);
	i = check_length_field(str, &list, i);
	j = i;
	list.conv_id = str[i];
	str[i] == 'u' || str[i] == 'U' ? list.base_nb = 10 : 0;
	str[i] == 'p' ? list.base_nb = 16 : 0;
	str[i] == 'X' ? list.base_nb = 16 : 0;
	str[i] == 'x' ? list.base_nb = 16 : 0;
	str[i] == 'o' || str[i] == 'O' ? list.base_nb = 8 : 0;
	list.size = list.conv_id ? i : j - 1;
	get_type(&list);
	return (list);
}
