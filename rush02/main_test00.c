/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:04:38 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/27 16:32:47 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
#include <stdio.h>

// char	*check_number(char *num) // написать!
// {
// 	//проверяем на правильность числа и осекаем лишние нули!
// }
void		ft_insert_dict(char *buf, t_btree **root)
{
	//char *key;
	char *value;
	
	value = ft_strcpy(buf, ft_strlen(buf));
	//key = ft_donumber(buf);
	//value = ft_doword(buf);
	if ("0")
		btree_insert_data(root, "0", value, ft_cmp);
}

int		main(int argc, char **argv)
{
	int fd;
	char ch[1];
	char buf[100];
	t_btree *root;
	// char *value;


	root = 0;
	int i = 0;

	if(argc < 2)
	{	
		PRINT_ERROR;
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{	
		PRINT_ERROR;
		return (0);
	}
	while (read(fd, ch, 1) > 0)
	{
		if (ch[0] != '\n')
			buf[i] = ch[0];
		i++;
		if (ch[0] == '\n')
		{
			buf[i] = 0;
			ft_insert_dict(buf, &root);
			i = 0;
		}
		
	}
	buf[i] = 0;
	ft_insert_dict(buf, &root);
	//printf("%s ==> ", num); // И здесь мы записываем значения в нашу связанную структуру структуру 
	//printf("%s \n", word); // так как я не понял как сделать иначе)

	close(fd);
	puts("=========================prefix=============================\n");

	puts("prefix\n");
	btree_apply_prefix(root, print_tree_item);
	puts("\n");

	// puts("==========================test 00 search============================\n");
	// //char numsearsh = "1";
	// value = btree_search_item(root, "20", ft_cmp);
	// printf("%s its is 20 \n", value);

	// puts("==========================test 01 searchsearch============================\n");

	// //for (int i = 0; i < 20)
	// print_number_main("21000", root);

return (0);
}