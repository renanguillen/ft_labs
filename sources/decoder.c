/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:13 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 11:49:32 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

int	main(void)
{
	t_compact	*data;

	data = (t_compact *)calloc(1, sizeof(t_compact));
	data->dictionary = (char **)calloc(128, sizeof(char *));
	decoder_shm(data);
	decoder_decompress(data);
	return (0);
}
