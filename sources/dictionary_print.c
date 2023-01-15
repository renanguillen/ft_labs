/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:11:48 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 13:11:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	print_dict(char **dict)
{
	int	i;

	i = 0;
	printf("\n\t-------Dicionário -------\n");
	while(i < 128)
	{
		if (strlen(dict[i]) > 0)
			printf("\t%d: %s\n", i, dict[i]);
		i++;
	}
}
