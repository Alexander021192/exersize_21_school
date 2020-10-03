/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:28:58 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/28 11:59:44 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"
#include <stdio.h>

char	*print_number(char num, t_btree *root)
{
	char *value;
	char number[2];

	number[0] = num;
	number[1] = 0;

	if ((value = btree_search_item(root, number, ft_cmp)) == 0)
		return ("error");
	return (value);
}

char	*print_number_hundred(char num, t_btree *root)
{
	char *value;
	char num_hundred[2];
	
	num_hundred[0] = num;
	num_hundred[1] = 0;
	
	value = btree_search_item(root, num_hundred, ft_cmp);
	if(!value)
		return (value);
	else
	{
		return (ft_strmall (value, btree_search_item(root, "100", ft_cmp)));
	}
}

char	*print_number_decimal(char num1, char num2, t_btree *root)
{
	char *value;
	char decimal[3];

	value = 0;
	decimal[0] = num1;
	decimal[1] = num2;
	decimal[2] = 0;
	
	if ((value = btree_search_item(root, decimal, ft_cmp)) == 0)
		return ("error");
	return (value);

}
char	*print_number_capacity(char num, char num0, int capacity, t_btree *root)
{
	char *value;
	char cap[capacity + 2];
	char number[2];

	number[0] = num;
	number[1] = 0; 

	cap[0] = '1';
	cap[capacity + 1] = 0;
	value = btree_search_item(root, number, ft_cmp);
	if (num == '0' || num0 == '1')
		value = "";
	while (capacity > 0)
	{
		cap[capacity] = '0';
		capacity--;
	}
	if(ft_strlen(cap) > 3)
	{
		value = ft_strmall(value, btree_search_item(root, cap, ft_cmp));
	}
	return (value);
}

char	*print_number_main(char *num, t_btree *root)
{
	int len;
	int i;
	char *num_str;

	num_str = "";
	i = 0;
	len = ft_strlen(num);
	while(num[i])
	{
		if (len % 3 == 0 &&  num[i] != '0')
			num_str = ft_strmall(num_str, print_number_hundred(num[i], root));
		else if (len % 3 == 2 && num[i] != '0')
		{
			if (len > 0 && num[i] == '1')
			{
				num_str = ft_strmall(num_str, print_number_decimal(num[i], num[i + 1], root)); 
				i++;
				len--;
			} 
			else
				num_str = ft_strmall(num_str, print_number_decimal(num[i], '0', root));
		}
		if (ft_strlen(num) == 1 && num[i] == '0')
			num_str = ft_strmall(num_str, print_number(num[i], root));
		else if (len % 3 == 1)
			num_str = ft_strmall(num_str, print_number_capacity(num[i], num[i - 1], (len - 1), root));
		i++;
		len--;
	}
	return (num_str);
}