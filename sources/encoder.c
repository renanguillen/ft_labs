/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:18 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:45:26 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

static void	clean_quit(t_data *data)
{
	dictionary_clear(data->dictionary);
	free(data->list);
	tree_free(data->tree);
	free(data->frequency);
	free(data->text);
	free(data->binary);
	return ;
}

int main(void)
{
	t_data	*data;

	data = (t_data *)calloc(1, sizeof(t_data));
	data->text = encoder_read_file(open("infile.txt", O_RDWR));
	if (strlen(data->text) == 0)
		return (1);
	huffman_action(data);
	encoder_shm(data);
	clean_quit(data);
	return (0);
}
