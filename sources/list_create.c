/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:43:54 by guribeir          #+#    #+#             */
/*   Updated: 2023/01/15 10:15:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

t_list	*list_create(void)
{
	t_list	*list;

	list = (t_list *)calloc(1, sizeof(t_list));
	list->start = NULL;
	list->size = 0;
	return (list);
}
