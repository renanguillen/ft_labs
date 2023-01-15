/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:58:03 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:34:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

t_node	*list_node_new(int *freq_table, int *i)
{
	t_node	*new_node;

	new_node = calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->c = *i;
	new_node->freq = freq_table[*i];
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}