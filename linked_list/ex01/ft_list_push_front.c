/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:01:28 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/23 18:27:36 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*begin;

	begin = (t_list*)malloc(sizeof(t_list));
	if (begin)
	{
		begin->data = data;
		begin->next = 0;
	}
	return (begin);	 
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_begin;

	new_begin = ft_create_elem(data);
	if (new_begin)
	{
		new_begin->next = *begin_list;
		*begin_list = new_begin;
	}
}

void off_list(struct s_list *begin)
{
	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin -> next;
	}
}

int main()
{
	t_list *begin;
	//t_list *new_begin;
	//t_list **begin_list;

	begin = ft_create_elem("friend");
	ft_list_push_front(&begin, "MY");
	ft_list_push_front(&begin, "HELLLO");
	

	off_list(begin);
}