/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:46:05 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/29 11:47:57 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_square
{
	t_point		start;
	t_point		end;
	int			max_width;
}				t_square;

#endif
