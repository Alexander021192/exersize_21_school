/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:53:50 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/24 18:59:02 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
void *data_ref, int (*cmp)(void *, void *))
{
	while(begin_list)
	{
		if(cmp(begin_list->data, data_ref) == 0)
		{
			f(begin_list->data);
			begin_list = begin_list->next;
		}	
	}
}