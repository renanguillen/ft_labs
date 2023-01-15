/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:56:10 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 14:56:20 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

int share_info(char *str, size_t size)
{
	int		shmid;
	key_t	key;
	char	*shmp;

	key = ftok(".shmfile", 65);
	shmid = shmget(key, size, 0644|IPC_CREAT);
	if (shmid == -1)
	{
		perror("Shared memory");
		return (1);
	}
	shmp = shmat(shmid, NULL, 0);
	if (shmp == (void *) -1)
	{
		perror("Shared memot attach");
		return (1);
	}
	memmove(shmp, str, size);
	printf("--- String compartilhada --- %s\n", shmp);
	sleep(5);
	if (shmdt(shmp) == -1)
	{
		perror("shmdt");
		return 1;
	}
	if (shmctl(shmid, IPC_RMID, 0) == -1)
	{
		perror("shmctl");
		return 1;
	}
	return (0);
}
