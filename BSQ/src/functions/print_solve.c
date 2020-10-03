/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:36:49 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/30 16:26:36 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

void	ft_print_solve(t_square solve, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_lines)
	{
		while (j < g_len_line)
		{
			if (i >= solve.start.y && i <= solve.end.y
			&& j >= solve.start.x && j <= solve.end.x)
				write(1, g_full, 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int		ft_print_error(char *msg)
{
	ft_print(msg);
	return (1);
}
