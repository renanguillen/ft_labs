/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:48:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 12:49:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

int	tree_height(t_node *root)
{
	int	left;
	int	right;
	
	if(root == NULL)
		return -1;
	else
	{
		left = tree_height(root->left) + 1;
		right = tree_height(root->right) + 1;
		if (left > right)
			return (left);
		else
			return (right);
	}
}
