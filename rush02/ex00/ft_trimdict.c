/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimdict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:57:17 by avaleera          #+#    #+#             */
/*   Updated: 2020/09/27 20:12:11 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

int		len_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != ':')
	{
		i++;
	}
	return (i);
}

char	*ft_donumber(char *str)
{
	char	*key;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(CHAR_NB))
		return (NULL);
	if ((key = (char *)malloc(sizeof(char *) * (len_nb(str) + 1))) == NULL)
		return (key);
	while (str[i] != ':')
	{
		if (CHAR_NB)
			key[j++] = str[i];
		else if ((!(CHAR_NB) && str[i] != ' '))
			return (NULL);
		i++;
	}
	key[j] = '\0';
	return (key);
}

int		len_val(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_doword(char *str)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	if (str[i + 1] == '\0')
		return (NULL);
	if (!(value = (char *)malloc(sizeof(char *) * (len_val(str, i) + 2))))
		return (value);
	while (str[i] != '\0')
	{
		value[j] = str[i];
		j++;
		i++;
	}
	value[j] = 0;
	return (value);
}
