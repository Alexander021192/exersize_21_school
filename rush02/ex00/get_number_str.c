/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:38:06 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/28 12:03:58 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void get_number_str(char *num, t_btree *root)
{
	char *number_main;

	number_main = ft_checknumber(num);

	if(number_main)
	{
		number_main = print_number_main(number_main, root);
		write(1, number_main, ft_strlen(number_main)); // и здесь нужна прога которая показывает что в строке есть ошибка
	}
	else
		write(1, "Wrong Number\n", 13);
}