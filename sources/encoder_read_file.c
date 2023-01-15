/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder_read_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:42:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:42:52 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

char	*encoder_read_file(int fd)
{
	char	*str;
	char	buf[1];
	int		i;

	str = NULL;
	i = 0;
	while (read(fd, buf, 1))
		i++;
	str = calloc(1, i + 1);
	close(fd);
	open("infile.txt", O_RDWR);
	read(fd, str, i);
	str[i] = '\0';
	return (str);
}
