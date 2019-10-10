/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_exception.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:20:34 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/07 15:36:13 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_to_excep(char *str, t_pflist *list)
{
	int len;

	len = 0;
	if ((list->param << FWIDTH) & MASK)
	{
		len = list->field_width - ft_strlen(str);
		if (len > 0)
			return (ft_strjoin_free_order(ft_strdup(str), width_str(len, ' '),
						1, !((list->param << FMINUS) & MASK)));
	}
	return (ft_strdup(str));
}

int		verify_mantissa(char *mantissa)
{
	int i;

	i = 2;
	while (mantissa[i])
	{
		if (mantissa[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

char	*double_exception1(char *mantissa, t_pflist *list, int m)
{
	char *str;

	str = NULL;
	if (mantissa[1] == '0' && !m)
	{
		if (list->double_param.sign)
			str = list->conv_id == 'F' ? "-INF" : "-inf";
		else
		{
			if ((list->param << FPLUS & MASK))
				str = list->conv_id == 'F' ? "+INF" : "+inf";
			else if ((list->param << FSPACE & MASK))
				str = list->conv_id == 'F' ? " INF" : " inf";
			else
				str = list->conv_id == 'F' ? "INF" : "inf";
		}
	}
	else
		str = list->conv_id == 'F' ? "NAN" : "nan";
	return (str);
}

char	*double_exception(char *mantissa, t_pflist *list)
{
	char	*str;
	int		m;

	m = verify_mantissa(mantissa);
	if (mantissa[0] == '0')
	{
		if (mantissa[1] == '1' || (mantissa[1] == '0' && m))
			str = list->conv_id == 'F' ? "NAN" : "nan";
		else if (list->double_param.sign)
			str = list->conv_id == 'F' ? "-INF" : "-inf";
		else
		{
			if ((list->param << FPLUS & MASK))
				str = list->conv_id == 'F' ? "+INF" : "+inf";
			else if ((list->param << FSPACE & MASK))
				str = list->conv_id == 'F' ? " INF" : " inf";
			else
				str = list->conv_id == 'F' ? "INF" : "inf";
		}
	}
	if (mantissa[0] == '1')
		str = double_exception1(mantissa, list, m);
	return (width_to_excep(str, list));
}
