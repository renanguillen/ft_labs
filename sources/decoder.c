/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:13 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/13 23:07:56 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

int	main(void)
{
	int		shm_id;
	key_t	mem_key;
	char	*shm_text;
	char	*str = NULL;

	mem_key = 1234;
	shm_id = shmget(mem_key, SIZE, 0666);
	if (shm_id < 0)
		{perror("smhget error (client)\n");exit (1);}
	shm_text = shmat(shm_id, NULL, 0);
	if (shm_text == (char *) -1)
		{perror("smhget error (client)\n");exit (1);}
	str = strdup(shm_text);
	printf("%s\n", str);
	free(str);
	shm_text[30] = '*';
	shm_text[31] = '#';
	while(shm_text[31] != '*')
	str = strdup(shm_text);
	printf("%s\n", str);
	free(str);
	shm_text[30] = '*';
	shm_text[31] = '#';
	while(shm_text[31] != '*')
	str = strdup(shm_text);
	printf("%s\n", str);
	free(str);
	shm_text[30] = '*';
	shm_text[31] = '#';
	printf("\nServer is done\n");
	shmdt(shm_text);
}
