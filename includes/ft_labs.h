/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:41:06 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/01/13 15:37:36 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LABS_H
# define FT_LABS_H

#define SIZE 100

typedef struct s_test
{
	int		number;
	char	letter;
	struct	s_test *next;
}	t_test;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/types.h>

#endif
