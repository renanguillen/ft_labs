/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:58:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 12:59:11 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	fill_list(int *freq_table, t_list *list)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < 128)
	{
		if (freq_table[i] > 0)
		{
			new_node = create_node(freq_table, &i);
			if (!new_node)
				return ;
			sorted_insert(list, new_node);
		}
		i++;
	}
}
