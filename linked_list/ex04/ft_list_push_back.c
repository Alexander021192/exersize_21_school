/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:21:45 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/23 20:47:57 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list 	*ft_list_last(t_list *begin_last)
{
	while (begin_last->next)
	{
		begin_last = begin_last -> next;
	}
	return (begin_last);
}

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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_last;
	t_list	*old_last;

	old_last = ft_list_last(*begin_list);
	new_last = ft_create_elem(data);
	if (new_last)
		old_last->next = new_last;
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
	ft_list_push_back(&begin, "MY");
	ft_list_push_back(&begin, "HELLLO");
	

	off_list(begin);
}