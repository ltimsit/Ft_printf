/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_new_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:53:14 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 16:18:14 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_ht_item		*ht_new_item(const char *key, const char *value)
{
	t_ht_item	*item;

	if (!(item = malloc(sizeof(t_ht_item))))
		return (NULL);
	if (!(item->key = ft_strdup(key)))
		return (NULL);
	if ((item->value = ft_strdup(value)))
		return (NULL);
	return (item);
}
