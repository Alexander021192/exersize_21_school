/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:28:40 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/29 18:20:31 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define MAP_ERROR "map error\n"
# define TRUE 1
# define FALSE 0
# define IS_PRINTABLE(x) ((x > 32 && x != 127) ? TRUE : FALSE)
# define IS_VALID(x, e, o, f) ((x == e || x == o || x == f) ? TRUE : FALSE)
# define IS_NUMBER(x) ((x >= '0' && x <= '9') ? TRUE : FALSE)
# define IS_LINE_BREAK(x) ((x == '\n') ? TRUE : FALSE)

# include "headers/prototypes.h"
# include "headers/types.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

int		g_lines;
int		g_len_line;
char	g_empty[1];
char	g_obst[1];
char	g_full[1];

#endif
