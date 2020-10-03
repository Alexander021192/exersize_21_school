/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:38:30 by gvelva            #+#    #+#             */
/*   Updated: 2020/09/27 19:26:13 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
#include <stdio.h>

char	*ft_checknumber(char *str)
{
	char	*key;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(CHAR_NB))
		return (NULL);
	if ((key = (char *)malloc(sizeof(char *) * (ft_strlen(str) + 1))) == NULL)
		return (key);
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (&str[0]);
	if (str[i] == '0')
		while (str[i] == '0')
			i++;
	while (str[i] != '\0')
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
