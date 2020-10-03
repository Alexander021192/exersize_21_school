/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:50:30 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/29 18:26:52 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int		ft_get_line_nbr(char *file, int end_index)
{
	char	l[end_index];
	char	*tmp;
	int		j;
	int		k;

	tmp = file;
	j = 0;
	k = end_index - 3;
	while (k >= 0)
	{
		if (!IS_NUMBER(tmp[k]))
			k--;
		else
		{
			l[j] = tmp[k];
			k--;
			j++;
		}
	}
	l[j] = 0;
	g_lines = ft_strnbr(ft_reverse_arr(l, end_index));
	return (g_lines);
}

int		is_valid_params(char *file)
{
	int		i;
	char	*tmp;

	tmp = file;
	i = line_size(tmp) - 1;
	if (i >= 3)
	{
		if (IS_PRINTABLE(tmp[i]))
			g_full[0] = tmp[i--];
		if (IS_PRINTABLE(tmp[i]) && tmp[i] != g_full[0])
			g_obst[0] = tmp[i--];
		if (IS_PRINTABLE(tmp[i]) && tmp[i] != g_full[0] && tmp[i] != g_obst[0])
			g_empty[0] = tmp[i--];
		if (!g_full[0] || !g_empty[0] || !g_obst[0])
			return (FALSE);
		while (i >= 0)
		{
			if (!IS_NUMBER(tmp[i]))
				return (FALSE);
			i--;
		}
	}
	else
		return (FALSE);
	return (TRUE);
}

int		is_valid_lines(char *file)
{
	int		i;
	int		l;
	int		line_breaks;

	i = line_size(file);
	l = ft_get_line_nbr(file, i - 1);
	if (l <= 0)
		return (FALSE);
	file += i + 1;
	line_breaks = 0;
	i = line_size(file);
	while (*file)
	{
		if (!(IS_VALID(*file, g_empty[0], g_obst[0], g_full[0])
			|| *file == '\n'))
			return (FALSE);
		else if (IS_LINE_BREAK(*file))
			line_breaks++;
		file++;
	}
	if (line_breaks == l)
		return (TRUE);
	else
		return (FALSE);
}

int		equal_lines(char *file)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	tmp = file;
	tmp = tmp + line_size(tmp) + 1;
	i = line_size(tmp);
	while (*tmp)
	{
		if (*tmp == '\n')
		{
			if (i != j)
				return (FALSE);
			else
				j = -1;
		}
		j++;
		tmp++;
	}
	g_len_line = i;
	return (TRUE);
}

int		ft_validator(char *file)
{
	if (ft_str_len(file) > 1)
	{
		if (is_valid_params(file) == TRUE
		&& is_valid_lines(file) == TRUE
		&& equal_lines(file) == TRUE)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}
