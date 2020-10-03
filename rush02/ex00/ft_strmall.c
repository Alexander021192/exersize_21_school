/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:27:21 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/28 12:02:27 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = ' ';
	dest[i + 1] = '\0';
	return (dest);
}

char *ft_strmall(char *last_value, char *find_value )
{
	int		n;
	char	*new_value;
	if (ft_cmp(find_value, "error") == 0)
		return ("error");
	n = ft_strlen(last_value) + ft_strlen(find_value) + 2;
	new_value = malloc(sizeof(char *) * n);
	ft_strcat(new_value, last_value);
	ft_strcat(new_value, find_value);
	new_value[ft_strlen(new_value) - 1] = 0;
	return (new_value);
}
