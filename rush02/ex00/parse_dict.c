/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:04:38 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/27 20:42:25 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void		ft_insert_dict(char *buf, t_btree **root)
{
	char *key;
	char *value;

	key = ft_donumber(buf);
	value = ft_doword(buf);
	if (key)
		btree_insert_data(root, key, value, ft_cmp);
}

t_btree		*parse_dict(int fd)
{
	int		i;
	char	ch[1];
	char	buf[100];
	t_btree	*root;

	root = 0;
	i = 0;
	while (read(fd, ch, 1) > 0)
	{
		if (ch[0] != '\n')
		{
			buf[i] = ch[0];
			i++;
		}
		if (ch[0] == '\n')
		{
			buf[i] = 0;
			ft_insert_dict(buf, &root);
			i = 0;
		}
	}
	if (read(fd, ch, 1) == -1)
		return (root);
	buf[i] = 0;
	ft_insert_dict(buf, &root);
	return (root);
}
