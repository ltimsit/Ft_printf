/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_del_hash_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:05:13 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 16:14:07 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ht_del_hash_table(t_hash_table *ht)
{
	unsigned int	i;
	t_ht_item		*item;

	i = 0;
	while (i < ht->size)
	{
		item = ht->items[i];
		if (item)
			ht_del_item(item);
		i++;
	}
	free(ht->items);
	free(ht);
}
