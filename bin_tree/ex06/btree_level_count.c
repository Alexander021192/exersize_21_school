/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:49:11 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/25 23:38:03 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int left;
	int right;

	left = 0;
	right = 0;
	if (root != 0)
	{
		left = btree_level_count(root->left);
		right = btree_level_count(root->right);
		if (left > right)
			return (left + 1);
		else
			return (right + 1);
	}
	else
		return (0);
}
