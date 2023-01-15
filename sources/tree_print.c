/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:50:09 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/14 12:50:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_labs.h"

void	print_tree(t_node *root, int size)
{
	if (root->left == NULL && root->right == NULL)
		printf("\tFolha: %c\tAltura: %d\n", root->c, size);
	else
	{
		print_tree(root->left, size + 1);
		print_tree(root->right, size + 1);
	}
}
