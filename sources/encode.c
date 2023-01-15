/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:53:44 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 14:53:57 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

char	*encode(char **dict, char *str)
{
	char	*code;
	int		i;
	int		size;

	i = 0;
	size = get_str_size(dict, str);	
	code = calloc(size, sizeof(char)); // será q aqui n é size + 1?
	while(str[i])
	{
		strcat(code, dict[(int)(str[i])]);
		i++;
	}
	return (code);
}