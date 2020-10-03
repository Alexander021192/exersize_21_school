/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:45:34 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/30 12:19:36 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

t_square	ft_create_new_square(int i, int j, int max_width)
{
	t_square solve;

	solve.start.x = j;
	solve.start.y = i;
	solve.end.x = j + max_width - 1;
	solve.end.y = i + max_width - 1;
	solve.max_width = max_width;
	return (solve);
}

int			ft_found_obstacle(char **map, t_point start, t_point end)
{
	int		i;
	int		j;

	i = start.y;
	j = start.x;
	while (i <= end.y && end.y < g_lines)
	{
		while (j <= end.x && end.x < g_len_line)
		{
			if (map[i][j] == g_obst[0])
				return (0);
			j++;
		}
		j = start.x;
		i++;
	}
	return (end.x - start.x + 1);
}

int			ft_increase_square(int i, int j, char **map, int max_width)
{
	t_point start;
	t_point end;

	start.x = j;
	start.y = i;
	end.x = j + max_width;
	end.y = i + max_width;
	while ((ft_found_obstacle(map, start, end) && end.x < g_len_line
			&& end.y < g_lines))
	{
		end.x++;
		end.y++;
	}
	return (end.x - start.x);
}

void		ft_solve(char **map)
{
	t_square	solve;
	int			max_width;
	int			i;
	int			j;

	max_width = 0;
	i = 0;
	j = 0;
	solve = ft_create_new_square(i, j, max_width);
	while (i < g_lines)
	{
		while (j < g_len_line)
		{
			max_width = ft_increase_square(i, j, map, solve.max_width);
			if (max_width > solve.max_width)
				solve = ft_create_new_square(i, j, max_width);
			j += (max_width == 0) ? 1 : max_width;
		}
		j = 0;
		i++;
	}
	ft_print_solve(solve, map);
}
