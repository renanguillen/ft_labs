/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:10:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 13:13:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	create_dict(char **dict, t_node *root, char *direction, int height)
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
		create_dict(dict, root->left, left, height);
		create_dict(dict, root->right, right, height);
	}
}
