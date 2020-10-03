/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:45:20 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/30 16:18:47 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

char	*ft_strcat(char *file, char buff[], int bytes_ret)
{
	char	*new;
	int		i;
	int		j;

	new = (char*)malloc(ft_str_len(file) + bytes_ret + 1);
	i = 0;
	while (*file)
	{
		new[i] = *file;
		i++;
		file++;
	}
	j = 0;
	while (j < bytes_ret)
	{
		new[i] = buff[j];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}
