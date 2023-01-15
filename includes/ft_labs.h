/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:06 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 11:51:33 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LABS_H
# define FT_LABS_H

# define SIZE 100

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_node
{
	int				freq;
	char			c;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*start;
	int		size;
}	t_list;

typedef struct s_data
{
	char	*text;
	int		*frequency;
	t_list	*list;
	t_node	*tree;
	int		height;
	char	**dictionary;
	char	*binary;
	char	*compressed;
}	t_data;

typedef struct s_compact
{
	int		len;
	char	**dictionary;
	char	*compressed;
	char	*binary;
	char	*text;
}	t_compact;

typedef struct s_shm
{
	int		id1;
	int		id2;
	key_t	key1;
	key_t	key2;
	char	*text;
	int		*numb;
}	t_shm;


void	decoder_decompress(t_compact *data);
void	decoder_shm(t_compact *data);
void	dictionary_clear(char **ptrs);
void	dictionary_create(char **dict, t_node *root, char *direction, int height);
char	**dictionary_init(int	height);
char	*encoder_read_file(int fd);
void	encoder_shm(t_data *data);
int		get_str_size(char **dict, char *str);
void	huffman_action(t_data *data);
char	*huffman_binary(char **dict, char *str);
char	*huffman_compress(char *code);
t_list	*list_create();
void	list_fill(int *freq_table, t_list *list);
t_node	*list_node_new(int *freq_table, int *i);
t_node	*list_node_remove(t_list *list);
void	list_sorted_insert(t_list *list, t_node *node);
t_node	*tree_build(t_list *list);
int		tree_height(t_node *root);
void	tree_free(t_node *tree);

#endif
