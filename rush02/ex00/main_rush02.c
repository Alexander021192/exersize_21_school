/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rush02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:13:19 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/27 19:46:29 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_btree	*root;

	fd = 0;
	if (argc > 3)
	{
		write(2, "Too many arguments\n", 19);
		return (0);
	}
	if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	else if (argc == 2)
		fd = open("number.dict", O_RDONLY);
	if (check_fd(fd))
		return (0);
	else
		root = parse_dict(fd);
	if (!root)
	{
		PRINT_ERROR;
		return (0);
	}
	
	else if (argc == 3)
		get_number_str(argv[2], root);
	else if (argc == 2)
		get_number_str(argv[1], root);
	return (0);
}
