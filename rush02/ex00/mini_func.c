/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:31:35 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/27 20:18:18 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"


int		ft_cmp(char *s1, char *s2)
{
	int i;
	
	i  = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_strlen(char *str)
{
	int i;
	
	i  = 0;
	while (str[i])
		i++;
	return (i);
}

char 	*ft_strcpy(char *str, int len)
{
	char *copy;
	int i;

	copy = malloc(len + 1);
	i = 0;
	while(str[i])
	{
		copy[i] = str[i];
		i++;
	}
	return(copy);
}

int		check_fd(int fd)
{
	if (fd < 0)
	{
		PRINT_ERROR;
		puts("here");
		return (1);
	}
	return (0);
}

char	*ft_kostyl(char *num)
{
	int 	i;
	int		len;
	char	*newnum;

	i = 0;
	len = ft_strlen(num) - 1;
	newnum = (char *)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		newnum[i] = num[i];
		i++;
	}
	newnum[i] = '\0';
	return (newnum);
}