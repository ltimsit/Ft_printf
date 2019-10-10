/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:57:10 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 16:03:04 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_hash_table	*ht_new(size_t size)
{
	t_hash_table *new;

	if (!(new = malloc(sizeof(t_hash_table))))
		return (NULL);
	new->size = size;
	new->count = 0;
	if (!(new->items = ft_memalloc(size * sizeof(t_ht_item *))))
		return (NULL);
	return (new);
}
