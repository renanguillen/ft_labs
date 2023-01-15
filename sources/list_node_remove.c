/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:58:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 12:58:37 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

t_node	*remove_node(t_list *list)
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
