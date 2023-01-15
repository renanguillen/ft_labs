/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:06 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 09:42:44 by ridalgo-         ###   ########.fr       */
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
	int		*freq_table;
	t_list	*list;
	t_node	*tree;
	int		height;
	char	**dict;
	char	*code;
	char	*bin;
}	t_data;

typedef struct s_shm
{
	int		id1;
	int		id2;
	key_t	key1;
	key_t	key2;
	char	*text;
	int		*numb;
}	t_shm;


t_list	*create_list();
void	sorted_insert(t_list *list, t_node *node);
t_node	*create_node(int *freq_table, int *i);
void	fill_list(int *freq_table, t_list *list);
void	print_list(t_list *list);
void	print_tree(t_node *root, int size);
t_node	*build_tree(t_list *list);
t_node	*remove_node(t_list *list);
int		tree_height(t_node *root);
char	**init_dict(int	height);
void	create_dict(char **dict, t_node *root, char *direction, int height);
void	print_dict(char **dict);
void	clear_dict(char **ptrs);
void	lstclear(t_node **lst);
void	free_tree(t_node *tree);
char	*encode(char **dict, char *str);
char	*decode(char *str, char**dict);
char	*compress(char *code);
char	*decompress(char *zip, int len);
int		get_str_size(char **dict, char *str);
void	encoder_shm(t_data *data);


#endif
