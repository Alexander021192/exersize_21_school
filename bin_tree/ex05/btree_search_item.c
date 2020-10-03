/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 21:35:22 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/25 22:36:57 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	void *result;

	result = 0;
	if (root->left)
		result = btree_search_item(root->left, data_ref, cmpf);
	if (result == 0 && (cmpf(root->item, data_ref) == 0))
		return (root->item);
	if (result == 0 && root->right)
		result = btree_search_item(root->right, data_ref, cmpf);
	return (result);
}
