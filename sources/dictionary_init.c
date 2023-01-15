/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:42:02 by guribeir          #+#    #+#             */
/*   Updated: 2023/01/15 10:26:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

char	**dictionary_init(int	height)
{
	char	**dict;
	int		i;

	dict = calloc(128, sizeof(char *));
	if (!dict)
		return (NULL);
	i = 0;
	while(i < 128)
	{
		dict[i] = calloc(height, sizeof(char));
		i++;
	}
	return (dict);
}
