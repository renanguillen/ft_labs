/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:59:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 12:59:34 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	print_list(t_list *list)
{
	t_node	*tmp;

	tmp = list->start;
	printf("----------- Lista Ordenada -----------\n Tamanho: %d\n", list->size);
	while(tmp)
	{
		printf("O caractere %c aparece %d vezes\n", tmp->c, tmp->freq);
		tmp = tmp->next;
	}
}
