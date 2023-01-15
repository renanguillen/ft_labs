/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:57:29 by guribeir          #+#    #+#             */
/*   Updated: 2023/01/14 12:49:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

t_node	*build_tree(t_list *list)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*new;

	while(list->size > 1)
	{
		n1 = remove_node(list);
		n2 = remove_node(list);
		new = calloc(sizeof(t_node), 1);
		if (!new)
			return(NULL);
		new->c = 2; //será q isso daqui vai dar b.o.? deixar o nome assim sem nd
		new->freq = (n1->freq + n2->freq);
		new->left = n1;
		new->right = n2;
		new->next = NULL;
		sorted_insert(list, new);
	}
	return (list->start);
}
