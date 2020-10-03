/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:06:23 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/27 20:17:18 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define PRINT_ERROR write(1, "Dict Error\n", 11)
# define CHAR_NB str[i] >= '0' && str[i] <= '9'

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	char			*key;
	char			*value;
}					t_btree;

int					check_fd(int fd);
int					ft_strlen(char *str);
char				*ft_strcpy(char *str, int len);
int					ft_cmp(char *str1, char *str2);
char				*ft_kostyl(char *num);


void				btree_apply_prefix(t_btree *root,
					void (*applyf)(char *, char *));
void				print_tree_item(char *key, char *value);


void				ft_insert_dict(char *buf, t_btree **root);

t_btree				*btree_create_node(char *key, char *value);
void				btree_insert_data(t_btree **root, char *key, char *value,
					int (*cmpf)(char *, char *));
char				*btree_search_item(t_btree *root, char *key,
					int (*cmpf)(char *, char *));

t_btree				*parse_dict(int fd);
void 				get_number_str(char *num, t_btree *root);
char				*ft_checknumber(char *num);
char				*ft_strmall(char *s1, char *s2);

char				*print_number(char num, t_btree *root);
char				*print_number_decimal(char num1, char num2, t_btree *root);
char				*print_number_hundred(char num, t_btree *root);
char				*print_number_main(char *num, t_btree *root);
char				*print_number_capacity(char num, char num0,
int capacity, t_btree *root);

char				*ft_donumber(char *str);
char				*ft_doword(char *str);



#endif
