/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:18 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 09:20:50 by ridalgo-         ###   ########.fr       */
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

int main(void)
{
	t_data	*data;

	data = (t_data *)calloc(1, sizeof(t_data));
	data->str = read_file(open("infile.txt", O_RDWR));
	if (strlen(data->str) == 0)
		return (1);
	data->freq_table = count_sym(data->str);
	data->list = create_list();
	fill_list(data->freq_table, data->list);
	data->tree = build_tree(data->list);
	data->height = tree_height(data->tree);
	data->dict = init_dict(data->height + 1);
	create_dict(data->dict, data->tree, "", data->height);
	data->code = encode(data->dict, data->str);
	// printf("String codificada:%s\n", data->code);
	data->bin = compress(data->code);
	// printf("\nString compactada:%s\n", data->bin);
	shm_encoder(data);
	clean_quit(data->dict, data->list, data->tree,
				data->freq_table, data->str, data->code);
	return (0);
}
