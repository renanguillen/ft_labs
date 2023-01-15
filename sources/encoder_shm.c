/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder_shm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:15:48 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 09:53:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

static void	shm_get_memory(t_shm *shm)
{
	shm->key1 = ftok(".shmkey1", SIZE);
	shm->key2 = ftok(".shmkey2", SIZE);
	shm->id1 = shmget(shm->key1, SIZE, IPC_CREAT | 0666);
	if (shm->id1 < 0)
		{perror("smhget error (server)\n");exit (1);}
	shm->text = shmat(shm->id1, NULL, 0);
	if (shm->text == (char *) -1)
		{perror("smhget error (server)\n");exit (1);}
	shm->id2 = shmget(shm->key2, SIZE, IPC_CREAT | 0666);
	if (shm->id2 < 0)
		{perror("smhget error (server)\n");exit (1);}
	shm->numb = shmat(shm->id2, NULL, 0);
	if (shm->numb == (int *)-1)
		{perror("smhget error (server)\n");exit (1);}
	return ;
}

static void	shm_send_compact(t_shm *shm, t_data *data)
{
	*shm->text = '0';
	*shm->numb = strlen(data->code);
	*(shm->text + 1) = '1';
	while(*shm->text == '0'){}
	*shm->numb = 0;
	memcpy(shm->text, data->bin, strlen(data->bin));
	shm->text[strlen(data->bin)] = 0;
	*(shm->numb + 1) = 1;
	while(*shm->numb == 0){}
	return ;
}

static void	shm_send_dictionary(t_shm *shm, t_data *data)
{
	int	i;
	i = 0;
	while(i < 128)
	{
		*shm->numb = 0;
		memcpy(shm->text, data->dict[i], strlen(data->dict[i]));
		shm->text[strlen(data->dict[i])] = 0;
		*(shm->numb + 1) = 1;
		while(*shm->numb == 0){}
		i++;
	}
	*(shm->numb + 1) = 1;
	return ;
}

void	encoder_shm(t_data *data)
{
	t_shm	*shm;

	shm = (t_shm *)calloc(1, sizeof(t_shm));
	shm_get_memory(shm);
	shm_send_compact(shm, data);
	shm_send_dictionary(shm, data);
	shmdt(shm->text);
	shmdt(shm->numb);
	shmctl(shm->id1, IPC_RMID, NULL);
	shmctl(shm->id2, IPC_RMID, NULL);
}
