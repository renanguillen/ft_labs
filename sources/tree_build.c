/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:57:29 by guribeir          #+#    #+#             */
/*   Updated: 2023/01/15 10:33:10 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

t_node	*tree_build(t_list *list)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*new;

	while(list->size > 1)
	{
		n1 = list_node_remove(list);
		n2 = list_node_remove(list);
		new = calloc(sizeof(t_node), 1);
		if (!new)
			return(NULL);
		new->c = 2; //será q isso daqui vai dar b.o.? deixar o nome assim sem nd
		new->freq = (n1->freq + n2->freq);
		new->left = n1;
		new->right = n2;
		new->next = NULL;
		list_sorted_insert(list, new);
	}
	return (list->start);
}
