/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_and_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:21:01 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/28 11:59:05 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
#include <stdio.h>

t_btree		*btree_create_node(char *key, char *value)
{
	t_btree	*new;

	new = (t_btree*)malloc(sizeof(t_btree));
	if (new)
	{
		new->left = 0;
		new->right = 0;
		new->key = key;
		new->value = value;
	}
	return (new);
}

void		btree_insert_data(t_btree **root, char *key, char *value,
		int (*cmpf)(char *, char *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(key, value);
	}
	else if (cmpf(key, (*root)->key) >= 0)
	{
		btree_insert_data(&((*root)->right), key, value, cmpf);
	}
	else if (cmpf(key, (*root)->key) < 0)
	{
		btree_insert_data(&((*root)->left), key, value, cmpf);
	}
}

char		*btree_search_item(t_btree *root, char *key,
int (*cmpf)(char *, char *))
{
	char *result;

	result = 0;
	if (root->left)
		result = btree_search_item(root->left, key, cmpf);
	if (result == 0 && (cmpf(root->key, key) == 0))
		return (root->value);
	if (result == 0 && root->right)
		result = btree_search_item(root->right, key, cmpf);
	return (result);
}
