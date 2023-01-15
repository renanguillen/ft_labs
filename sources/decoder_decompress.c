/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:49:38 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 11:50:32 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

static int	is_one(char byte, int i)
{
	char	aux;

	aux = (1 << i);
	return byte & aux;
}

static char	*decompress(char *zip, int len)
{
	int		i;
	int		pos;
	char	*str;
	int		res;
	char	c[2];

	i = 0;
	pos = 7;
	str = calloc(len, sizeof(char));
	res = len % 8;
	if (res == 0)
	{
		while(zip[i])
		{
			while(pos >= 0)
			{
				if(is_one(zip[i], pos))
					strcat(str, "1");
				else
					strcat(str, "0");
				pos--;
			}
			pos = 7;
			i++;
		}
	}
	else
	{
		while((strlen(str) < (unsigned long)(len - res)) && zip[i])
		{
			while(pos >= 0)
			{
				if(is_one(zip[i], pos))
					strcat(str, "1");
				else
					strcat(str, "0");
				pos--;
			}
			pos = 7;
			i++;
		}
		while (zip[i])
		{
			c[0] = zip[i];
			c[1] = '\0';
			strcat(str, c);
			i++;
		}
	}
	return (str);
}

static char	*decode(char *str, char**dict)
{
	char	*new_str;
	int		j;
	char	c[2];
	
	j = 0;
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

void	decoder_decompress(t_compact *data)
{
	data->binary = decompress(data->compressed, data->len);
	data->text = decode(data->binary, data->dictionary);
	printf("%s\n", data->text);
	return ;
}
