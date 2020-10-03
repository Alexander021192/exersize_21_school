/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:23:23 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/30 16:52:42 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_run_stdin(void)
{
	char	*file;
	char	buff[28000];
	int		bytes_ret;
	char	**map;

	file = malloc(1);
	file[0] = 0;
	while ((bytes_ret = read(0, buff, sizeof(buff))))
		file = ft_strcat(file, buff, bytes_ret);
	if (bytes_ret < 0)
		return (ft_print_error(MAP_ERROR));
	if (ft_validator(file) == TRUE)
	{
		map = ft_parse_map(file);
		ft_solve(map);
		ft_free_map(map);
	}
	else
	{
		ft_print(MAP_ERROR);
		exit(1);
	}
	free(file);
	return (0);
}

int		ft_run(char **argv)
{
	int		fd;
	int		had_error;

	argv++;
	had_error = 0;
	while (*argv)
	{
		printf("\n<<<%s>>>\n", *argv);
		fd = open(*argv, O_RDONLY);
		if (fd < 0)
		{
			ft_print(MAP_ERROR);
			had_error = 1;
		}
		else
			had_error += ft_read(fd, *argv);
		argv++;
	}
	return (had_error > 0 ? 1 : 0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_run_stdin());
	else if (argc > 1)
		return (ft_run(argv));
}
