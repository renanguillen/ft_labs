/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:53:10 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 21:36:26 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

char	*decode(char *str, char**dict)
{
	char	*new_str;
	int		j;
	char	c[2];
	
	j = 0;
	new_str = NULL;
	new_str = calloc(strlen(str), sizeof(char));
	while(*str)
	{
		if (strlen(dict[j]) > 0)
		{
			if(strncmp(dict[j], (str), strlen(dict[j])) == 0)
			{
				c[0] = j;
				c[1] = '\0';
				strncat(new_str, c, 1);
				str += strlen(dict[j]);
				j = -1;
			}
		}
		j++;
	}
	return (new_str);
}
