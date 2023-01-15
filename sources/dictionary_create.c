/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:10:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:29:10 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	dictionary_create(char **dict, t_node *root, char *direction, int height)
{
	char	left[height];
	char	right[height];

	if(root->left == NULL && root->right == NULL)
		strcpy(dict[(int)(root->c)], direction);
	else
	{
		strcpy(left, direction);
		strcpy(right, direction);
		strcat(left, "0");
		strcat(right, "1");
		dictionary_create(dict, root->left, left, height);
		dictionary_create(dict, root->right, right, height);
	}
}
