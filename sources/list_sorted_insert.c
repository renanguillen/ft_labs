/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorted_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:56:46 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:30:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	list_sorted_insert(t_list *list, t_node *node)
{
	t_node *tmp;

	if(list->start == NULL)
		list->start = node;
	else if (node->freq < list->start->freq)
	{
		node->next = list->start;
		list->start = node;
	}
	else
	{
		tmp = list->start;
		while(tmp->next && tmp->next->freq <= node->freq)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;
	}
	list->size++;
}
