/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:18 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 22:47:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

char	*read_file(int fd)
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

int	*count_sym(char *str)
{
	int	*freq_table;
	int	i;

	freq_table = calloc(128, sizeof(int));
	i = 0;
	while (i < 128)
		freq_table[i++] = 0;
	i = 0;
	while (str[i])
	{
		freq_table[(int)(str[i])]++;
		i++;
	}
	return (freq_table);
}

void	clean_quit(char **dict, t_list *list, t_node *tree, int *freq_table, char *str, char *code)
{
	clear_dict(dict);
	free(list);
	free_tree(tree);
	free(freq_table);
	free(str);
	free(code);
}

int main(int ac, char **av)
{
	(void)ac;
	int		*freq_table;
	t_list	*list;
	t_node	*tree;
	int		height;
	char	**dict;
	char	*code;
	char	*bin;

	int		shm_id1;
	int		shm_id2;
	key_t	mem_key1;
	key_t	mem_key2;
	char	*shm_text;
	int		*shm_int;
	int		i = 0;

	mem_key1 = 1234;
	mem_key2 = 4321;
	freq_table = count_sym(av[1]);
	list = create_list();
	fill_list(freq_table, list);
	tree = build_tree(list);
	height = tree_height(tree);
	dict = init_dict(height + 1);
	create_dict(dict, tree, "", height);
	code = encode(dict, av[1]);
	// printf("String codificada:%s\n", code);
	bin = compress(code);
	// printf("\nString compactada:%s\n", bin);
	//abrindo espaço de memória
	shm_id1 = shmget(mem_key1, SIZE, IPC_CREAT | 0666);
	if (shm_id1 < 0)
		{perror("smhget error (server)\n");exit (1);}
	shm_text = shmat(shm_id1, NULL, 0);
	if (shm_text == (char *) -1)
		{perror("smhget error (server)\n");exit (1);}
	shm_id2 = shmget(mem_key2, SIZE, IPC_CREAT | 0666);
	if (shm_id2 < 0)
		{perror("smhget error (server)\n");exit (1);}
	shm_int = shmat(shm_id2, NULL, 0);
	if (shm_int == (int *)-1)
		{perror("smhget error (server)\n");exit (1);}

	*shm_int = 0;
	memcpy(shm_text, code, strlen(code));
	shm_text[strlen(code)] = 0;
	*(shm_int + 1) = 1;
	while(*shm_int == 0){}

	*shm_int = 0;
	memcpy(shm_text, bin, strlen(bin));
	shm_text[strlen(bin)] = 0;
	*(shm_int + 1) = 1;
	while(*shm_int == 0){}

	while(i < 128)
	{
		*shm_int = 0;
		memcpy(shm_text, dict[i], strlen(dict[i]));
		shm_text[strlen(dict[i])] = 0;
		*(shm_int + 1) = 1;
		while(*shm_int == 0){}
		i++;
	}
	*(shm_int + 1) = 1;
	clean_quit(dict, list, tree, freq_table, av[1], code);
	shmdt(shm_text);
	shmdt(shm_int);
	shmctl(shm_id1, IPC_RMID, NULL);
	shmctl(shm_id2, IPC_RMID, NULL);
	return (0);
}
