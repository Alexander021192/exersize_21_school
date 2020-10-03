/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandee <jrandee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:27:00 by jrandee           #+#    #+#             */
/*   Updated: 2020/09/30 16:26:52 by jrandee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "types.h"

void	ft_solve(char **map);
int		line_size(char *file);
char	*ft_parse_params(char *file);
char	**ft_parse_map(char *file);
char	*parse_line(char *file);
int		ft_read(int fd, char *file_path);
int		ft_validator(char *file);
void	ft_print_solve(t_square solve, char **map);
int		ft_found_obstacle(char **map, t_point start, t_point end);
int		ft_increase_square(int i, int j, char **map, int max_width);
void	ft_free_map(char **map);
int		ft_print_error(char *msg);

char	*ft_reverse_arr(char str[], int size);
char	*ft_strcat(char *file, char buff[], int bytes_ret);
int		ft_str_len(char *str);
void	ft_print(char *str);
int		ft_get_file_size(int fd);
int		ft_strnbr(char *str);

#endif
