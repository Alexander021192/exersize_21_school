/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:02:43 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/25 22:04:24 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree	*new;

	new = (t_btree*)malloc(sizeof(t_btree));
	if (new)
	{
		new->left = 0;
		new->right = 0;
		new->item = item;
	}
	return (new);
}
