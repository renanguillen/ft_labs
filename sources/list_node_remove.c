/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:58:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:32:30 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

t_node	*list_node_remove(t_list *list)
{
	t_node	*tmp;

	tmp = NULL;
	if(list->start)
	{
		tmp = list->start;
		list->start = tmp->next;
		tmp->next = NULL;
		list->size--;
	}
	return (tmp);
}
