/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:22:50 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/25 22:13:54 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		*root = btree_create_node(item);
	else if (cmpf(item, (*root)->item) >= 0)
	{
		btree_insert_data(&((*root)->right), item, cmpf);
	}
	else if (cmpf(item, (*root)->item) < 0)
	{
		btree_insert_data(&((*root)->left), item, cmpf);
	}
}
