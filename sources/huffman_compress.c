/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:52:13 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:38:23 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

char	*huffman_compress(char *code)
{
	int		i;
	char	byte;
	char	aux;
	int		pos;
	char	*zip;
	char	c[2];
	int		res;
	
	i = 0;
	byte = 0;
	aux = 0;
	pos = 7;
	zip = calloc(strlen(code), sizeof(char));
	if (!zip)
		return NULL;
	res = strlen(code) % 8;
	if (res == 0)
	{
		while(code[i])
		{
			aux = 1;
			if (code[i] == '1')
			{
				aux = aux << pos;
				byte = byte | aux;
			}
			pos--;
			if (pos < 0)
			{
				c[0] = byte;
				c[1] = '\0';
				zip = strcat(zip, c);
				byte = 0;
				pos = 7;
			}
			i++;
		}
	}
	else
	{
		while(i < ((int)(strlen(code)) - res) && code[i])
		{
			aux = 1;
			if (code[i] == '1')
			{
				aux = aux << pos;
				byte = byte | aux;
			}
			pos--;
			if (pos < 0)
			{
				c[0] = byte;
				c[1] = '\0';
				zip = strcat(zip, c);
				byte = 0;
				pos = 7;
			}
			i++;
		}
		while (code[i])
		{
			c[0] = code[i];
			c[1] = '\0';
			zip = strcat(zip, c);
			i++;
		}
	}
	return (zip);
}