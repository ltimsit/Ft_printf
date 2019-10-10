/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubletoa3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:06:59 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/09 13:15:25 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_dot_error(char *result_ent, char *decimal, t_pflist *list)
{
	if (decimal[0] == '/')
		add_buff_to_result(result_ent, NULL, 0);
	if (decimal[0] == '-' && result_ent[ft_strlen(result_ent) - 1] % 2 == 1)
		add_buff_to_result(result_ent, NULL, 0);
	if (!((list->param << FHASH) & MASK) && (list->param << FPREC) & MASK &&
			list->field_precision == 0)
		decimal[0] = '\0';
	else
		decimal[0] = '.';
}

char	*check_sign_double(char *d_int, t_pflist *list)
{
	char *int_signed;
	char *sign;

	sign = "0";
	if (list->double_param.sign || ((list->param << FPLUS) & MASK ||
				(list->param << FSPACE) & MASK))
	{
		if (list->double_param.sign)
			sign = "-";
		else if ((list->param << FPLUS) & MASK)
			sign = "+";
		else if ((list->param << FSPACE) & MASK)
			sign = " ";
		if (d_int[0] == '0' && d_int[1])
		{
			d_int[0] = *sign;
			return (d_int);
		}
		if (!(int_signed = ft_strjoin_free_order(sign, d_int, 3, 0)))
			return (NULL);
		return (int_signed);
	}
	return (d_int);
}

char	*check_zero(char *result_ent, t_pflist *list, int dec_len)
{
	char	*d_int;
	int		ent_len;
	int		zero_len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (result_ent[i] == '0')
		i++;
	i -= result_ent[i] == 0 ? 1 : 0;
	zero_len = 0;
	ent_len = ft_strlen(result_ent + i);
	if (((list->param << FWIDTH) & MASK) && ((list->param << FZERO) & MASK))
		zero_len = (list->field_width - ent_len - dec_len) > 0 ?
			(list->field_width - ent_len - dec_len) : 0;
	if (!(d_int = (char *)malloc(sizeof(char) * (ent_len + zero_len + 1))))
		return (NULL);
	d_int[ent_len + zero_len] = '\0';
	while (j < zero_len)
		d_int[j++] = '0';
	while (result_ent[i])
		d_int[j++] = result_ent[i++];
	return (d_int);
}

char	*precision_to_decimal(char *d_decimal, t_pflist *list)
{
	int		len_prec;
	char	*decimal;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len_prec = (list->param << FPREC) & MASK ? list->field_precision + 1 : 7;
	if (!(decimal = (char *)malloc(sizeof(char) * len_prec + 1)))
		return (NULL);
	decimal[len_prec] = '\0';
	while (++i < len_prec && d_decimal[i])
		decimal[i] = d_decimal[i];
	while (i + j < len_prec)
		decimal[i + j++] = '0';
	if (!j && d_decimal[i] >= '5')
		double_round(d_decimal, decimal, i, check_d(d_decimal, i));
	return (decimal);
}

char	*get_final_str(t_pflist *list)
{
	char	*decimal;
	char	*d_int;
	char	*result;
	int		len;

	list->double_param.result_dec[0] = '.';
	if (!(decimal = precision_to_decimal(list->double_param.result_dec, list)))
		return (NULL);
	if (decimal[0] != '.' || (list->param << FPREC) & MASK)
		check_dot_error(list->double_param.result_ent, decimal, list);
	if (!(d_int = check_zero(list->double_param.result_ent, list,
			ft_strlen(decimal))))
		return (NULL);
	if (!(d_int = check_sign_double(d_int, list)))
		return (NULL);
	if (!(result = ft_strjoin_free_order(d_int, decimal, 1, 0)))
		return (NULL);
	if ((list->param << FWIDTH & MASK) &&
			(len = list->field_width - ft_strlen(result)) > 0)
		if (!(result = get_width_space_str(result, len, list)))
			return (NULL);
	return (result);
}
