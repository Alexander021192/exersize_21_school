/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:33:29 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/30 16:46:59 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int		ft_get_file_size(int fd)
{
	char	buff[2800];
	int		file_size;
	int		bytes_ret;

	file_size = 0;
	while ((bytes_ret = read(fd, buff, sizeof(buff))))
		file_size += bytes_ret;
	close(fd);
	return (file_size);
}

void	ft_free_map(char **map)
{
	int		i;

	i = 0;
	while (i < g_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		ft_read(int fd, char *file_path)
{
	char	*file;
	int		file_size;
	int		is_valid;
	char	**map;

	file_size = ft_get_file_size(fd);
	file = malloc(file_size + 1);
	fd = open(file_path, O_RDONLY);
	read(fd, file, file_size);
	file[file_size] = 0;
	close(fd);
	ft_print("\n============new solve================\n");
	is_valid = ft_validator(file);
	if (is_valid == TRUE)
	{
		map = ft_parse_map(file);
		ft_solve(map);
		ft_free_map(map);
	}
	else
	{
		free(file);
		return (ft_print_error(MAP_ERROR));
	}
	free(file);
	return (0);
}
