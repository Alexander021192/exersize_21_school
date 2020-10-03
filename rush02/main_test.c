/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:04:38 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/27 16:26:15 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
#include <stdio.h>

// char	*check_number(char *num) // написать!
// {
// 	//проверяем на правильность числа и осекаем лишние нули!
// }

int		main(int argc, char **argv)
{
	int fd;
	char ch[1];
	char buf[100];
	char *word;
	char *num;
	t_btree *root;
	// char *value;


	root = 0;
	int i = 0;
	int flag = 0;

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
		if( ch[0] != ':' && flag == 0 && ch[0] != ' ')
		{
			buf[i] = ch[0];
			i++;
		}
		else if(ch[0] == ':')
		{
			flag = 1;
			buf[i] = 0;
			num = ft_strcpy(buf, ft_strlen(buf));
			i = 0;
		}
		else if (ch[0] != '\n' && flag == 1)
		{
			buf[i] = ch[0];
			i++;
		}
		else if (ch[0] == '\n' || ch[0] == 0) // EOF не работает(
		{
			flag = 0;
			buf[i] = 0;
			word = ft_strcpy(buf, ft_strlen(buf));
			//printf("%s ==> ", num);  
			//printf("%s \n", word);
			if (word && num)
				btree_insert_data(&root, num, word, ft_cmp); // здесь мы записываем значения в нашу связанную структуру структуру
			i = 0;
		}
		
	}
	buf[i] = 0;
	word = ft_strcpy(buf, ft_strlen(buf));
	//printf("%s ==> ", num); // И здесь мы записываем значения в нашу связанную структуру структуру 
	//printf("%s \n", word); // так как я не понял как сделать иначе)
	btree_insert_data(&root, num, word, ft_cmp);
	
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