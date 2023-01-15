/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:46:48 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/15 10:46:11 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	tree_free(t_node *tree)
{
	if (tree)
	{
		if (tree->left)
			tree_free(tree->left);
		if (tree->right)
			tree_free(tree->right);
		free(tree);
	}
}
