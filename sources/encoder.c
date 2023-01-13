/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:18 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/13 23:08:41 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

int	main(void)
{
	int		shm_id;
	key_t	mem_key;
	char	*shm_text;
	char	letter;
	char	*str = "binario";
	char	*str2 = "001";
	char	*str3 = "101";

	mem_key = 1234;
	letter = 'a';
	shm_id = shmget(mem_key, SIZE, IPC_CREAT | 0666);
	if (shm_id < 0)
		{perror("smhget error (server)\n");exit (1);}
	shm_text = shmat(shm_id, NULL, 0);
	if (shm_text == (char *) -1)
		{perror("smhget error (server)\n");exit (1);}
	memcpy(shm_text, str, strlen(str));
	shm_text[strlen(str)] = 0;
	shm_text[30] = '#';
	shm_text[31] = '*';
	while (shm_text[30] != '*'){}
	memcpy(shm_text, str2, strlen(str2));
	shm_text[strlen(str3)] = 0;
	shm_text[30] = '#';
	shm_text[31] = '*';
	while (shm_text[30] != '*'){}
	memcpy(shm_text, str3, strlen(str2));
	shm_text[strlen(str3)] = 0;
	shm_text[30] = '#';
	shm_text[31] = '*';
	while (shm_text[30] != '*'){}
	shmdt(shm_text);
	shmctl(shm_id, IPC_RMID, NULL);
	return (0);
}
