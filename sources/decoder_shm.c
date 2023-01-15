/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder_shm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:45:51 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 11:46:05 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

static void	shm_get_memory(t_shm *shm)
{
	shm->key1 = ftok(".shmkey1", SIZE);
	shm->key2 = ftok(".shmkey2", SIZE);
	shm->id1 = shmget(shm->key1, SIZE, IPC_CREAT | 0666);
	if (shm->id1 < 0)
		{perror("smhget error (decoder)\n");exit (1);}
	shm->text = shmat(shm->id1, NULL, 0);
	if (shm->text == (char *) -1)
		{perror("smhmat error (decoder)\n");exit (1);}
	shm->id2 = shmget(shm->key2, SIZE, IPC_CREAT | 0666);
	if (shm->id2 < 0)
		{perror("smhget error (decoder)\n");exit (1);}
	shm->numb = shmat(shm->id2, NULL, 0);
	if (shm->numb == (int *)-1)
		{perror("smhmat error (decoder)\n");exit (1);}
	return ;
}
static void	shm_receive_compact(t_shm *shm, t_compact *data)
{
	*(shm->text + 1) = '0';
	data->len += *shm->numb;
	*shm->text = '1';
	while(*(shm->text + 1) == '0'){}
	*(shm->numb + 1) = 0;
	data->compressed = strdup(shm->text);
	data->compressed[strlen(shm->text)] = 0;
	*shm->numb = 1;
	while(*(shm->numb + 1) == 0){}
	return ;
}

static void	shm_receive_dictionary(t_shm *shm, t_compact *data)
{
	int	i;

	i = 0;
	while(i < 128)
	{
		*(shm->numb + 1) = 0;
		data->dictionary[i] = (char *)calloc(1000, sizeof(char));
		data->dictionary[i] = strcpy(data->dictionary[i], shm->text);
		*shm->numb = 1;
		while(*(shm->numb + 1) == 0){}
		i++;
	}
	return ;
}

void	decoder_shm(t_compact *data)
{
	t_shm		*shm;

	shm = (t_shm *)calloc(1, sizeof(t_shm));
	shm_get_memory(shm);
	shm_receive_compact(shm, data);
	shm_receive_dictionary(shm, data);
	shmdt(shm->text);
	shmdt(shm->numb);
}
