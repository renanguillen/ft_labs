/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:10:07 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:40:24 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

static int	*count_sym(char *str)
{
	int	*frequency;
	int	i;

	frequency = calloc(128, sizeof(int));
	i = 0;
	while (i < 128)
		frequency[i++] = 0;
	i = 0;
	while (str[i])
	{
		frequency[(int)(str[i])]++;
		i++;
	}
	return (frequency);
}

void	huffman_action(t_data *data)
{
	data->frequency = count_sym(data->text);
	data->list = list_create();
	list_fill(data->frequency, data->list);
	data->tree = tree_build(data->list);
	data->height = tree_height(data->tree);
	data->dictionary = dictionary_init(data->height + 1);
	dictionary_create(data->dictionary, data->tree, "", data->height);
	data->binary = huffman_binary(data->dictionary, data->text);
	data->compressed = huffman_compress(data->binary);
	return ;
}
