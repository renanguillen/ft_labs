/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:54:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 14:55:38 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

int	get_str_size(char **dict, char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while(str[i])
	{
		size = size + strlen(dict[(int)(str[i])]);
		i++;
	}
	return (size + 1);
}
