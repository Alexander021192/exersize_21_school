/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:42:11 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/29 18:29:29 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int		ft_str_len(char *str)
{
	int		len;

	len = 0;
	if (str)
		while (str[len] != '\0')
			len++;
	return (len);
}

void	ft_print(char *str)
{
	write(1, str, ft_str_len(str) + 1);
}

int		line_size(char *file)
{
	int len;

	len = 0;
	if (file)
		while (file[len] != '\n')
			len++;
	return (len);
}

char	*ft_reverse_arr(char str[], int size)
{
	char	reversed[size];
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		reversed[j] = str[i];
		j++;
		i--;
	}
	reversed[j] = 0;
	ptr = &reversed[0];
	return (ptr);
}

int		ft_strnbr(char *str)
{
	int		res;

	res = 0;
	while (*str)
	{
		res = 10 * res + (*str - 48);
		str++;
	}
	return (res);
}
