/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:11:30 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:45:32 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	dictionary_clear(char **ptrs)
{
	int	i;

	if (ptrs != NULL)
	{
		i = 0;
		while (i < 128)
		{
			if (ptrs[i] != NULL)
				free(ptrs[i]);
			i++;
		}
		free(ptrs);
		ptrs = NULL;
	}
}
