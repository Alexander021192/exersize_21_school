/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:48:53 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/30 11:42:14 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

char	*parse_line(char *file)
{
	char	*map_line;
	int		j;

	j = 0;
	map_line = (char*)malloc((g_len_line + 1) * sizeof(char*));
	while (*file != '\n')
	{
		map_line[j] = *file;
		j++;
		file++;
	}
	map_line[j] = 0;
	return (map_line);
}

char	**ft_parse_map(char *file)
{
	char	**map;
	int		i;

	i = 0;
	file = file + line_size(file) + 1;
	map = (char**)malloc(g_lines * sizeof(char*));
	while (*file)
	{
		map[i] = parse_line(file);
		i++;
		file += g_len_line + 1;
	}
	return (map);
}

// int		main(void)
// {
// 	return (0);
// }