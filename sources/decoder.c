/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:13 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 09:54:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

int	main(void)
{
	int		shm_id1;
	int		shm_id2;
	key_t	mem_key1;
	key_t	mem_key2;
	char	*shm_text;
	int		*shm_int;
	// char	*bin = NULL;
	char	*compact = NULL;
	char	**dict = NULL;
	int		i = 0;
	char	*new_code;
	char	*new_str;
	int		len = 0;

	mem_key1 = ftok(".shmkey1", SIZE);
	mem_key2 = ftok(".shmkey2", SIZE);
	shm_id1 = shmget(mem_key1, SIZE, 0666);
	if (shm_id1 < 0)
		{perror("smhget error (client)\n");exit (1);}
	shm_text = shmat(shm_id1, NULL, 0);
	if (shm_text == (char *) -1)
		{perror("smhget error (client)\n");exit (1);}
	shm_id2 = shmget(mem_key2, SIZE, IPC_CREAT | 0666);
	if (shm_id2 < 0)
		{perror("smhget error (server)\n");exit (1);}
	shm_int = shmat(shm_id2, NULL, 0);
	if (shm_int == (int *)-1)
		{perror("smhget error (server)\n");exit (1);}

	*(shm_text + 1) = '0';
	len += *shm_int;
	*shm_text = '1';
	while(*(shm_text + 1) == '0'){}

	*(shm_int + 1) = 0;
	compact = strdup(shm_text);
	compact[strlen(shm_text)] = 0;
	*shm_int = 1;
	while(*(shm_int + 1) == 0){}
	
	dict = (char **)calloc(128, sizeof(char *));
	while(i < 128)
	{
		*(shm_int + 1) = 0;
		dict[i] = (char *)calloc(1000, sizeof(char));
		dict[i] = strcpy(dict[i], shm_text);
		*shm_int = 1;
		while(*(shm_int + 1) == 0){}
		i++;
	}
	// i = 0;
	// while (i < 128)
	// {
	// 	printf("Dict[%d]:%s\n", i, dict[i]);
	// 	i++;
	// }
	
	new_code = decompress(compact, len);
	// printf("\nString codificada:%s\n", new_code);
	new_str = decode(new_code, dict);
	printf("%s\n", new_str);
	shmdt(shm_text);
	printf("\nClient is done\n");
}
