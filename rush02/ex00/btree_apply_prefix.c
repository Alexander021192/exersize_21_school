/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:15:37 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/26 20:00:40 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
#include <stdio.h>

void	print_tree_item(char *key, char *value)
{
	printf("%s ==>  ", key);
	printf(" %s\n", value);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(char *, char *))
{
	if (root)
	{
		applyf(root->key, root->value);
		if (root->left)
			btree_apply_prefix(root->left, applyf);
		if (root->right)
			btree_apply_prefix(root->right, applyf);
	}
}
