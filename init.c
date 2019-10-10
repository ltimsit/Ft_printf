/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:52:36 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/09 16:50:52 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

char	*call_fct(t_pflist list, va_list ap)
{
	int		i;
	char	*conv;

	i = 0;
	while (i != list.type)
		i++;
	if (!(conv = g_fct_tab[i](ap, &list)))
		return (NULL);
	return (conv);
}

char	*get_result(char *str, t_pflist pflist, int j, va_list ap)
{
	char	*result_cv;
	char	*conv;

	if (!(result_cv = ft_strndup(str, j)))
		return (NULL);
	if (!pflist.conv_id)
		return (result_cv);
	if (pflist.conv_id == '&' || pflist.conv_id == '@')
	{
		if (pflist.conv_id == '&')
			g_fd = va_arg(ap, unsigned int);
		else
			g_sptr = va_arg(ap, char**);
		return (result_cv);
	}
	if (pflist.conv_id < 10 || pflist.conv_id == '{')
	{
		if (!(conv = apply_color(&pflist)))
			return (NULL);
	}
	else if (!(conv = call_fct(pflist, ap)))
		return (NULL);
	if (!(result_cv = ft_strjoin_free_order(result_cv, conv, 1, 0)))
		return (NULL);
	return (result_cv);
}

char	*parse_str(char *str, char *result, va_list ap)
{
	int			j;
	t_pflist	pflist;

	pflist.param = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '%' || str[j] == '{')
		{
			pflist = str[j] == '%' ? check_arg(str + j, ap) :
				check_color(str + j);
			if (!(result = ft_strjoin_free_order(result ? result :
							ft_strnew(0),
							get_result(str, pflist, j, ap), 1, 0)))
				return (NULL);
			str += j + pflist.size + 1;
			j = 0;
		}
		else
			j++;
	}
	if (!(result = ft_strjoin_free_order((result ? result : ft_strnew(0)),
			str, 2, 0)))
		return (NULL);
	return (result);
}

void	fix_null_char(char *result)
{
	int j;

	j = 0;
	while (result[j])
	{
		if (result[j] == -1)
			result[j] = '\0';
		j++;
	}
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	char	*result;
	int		len_returned;

	g_fd = 1;
	g_sptr = NULL;
	result = NULL;
	va_start(ap, str);
	init_fct_tabs();
	if (!str || !(result = parse_str(str, result, ap)))
	{
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	len_returned = ft_strlen(result);
	fix_null_char(result);
	if (g_sptr)
		*g_sptr = ft_strndup(result, len_returned);
	if (g_fd <= OPEN_MAX)
		ft_putnstr_fd(result, g_fd, len_returned);
	free(result);
	return (len_returned);
}
