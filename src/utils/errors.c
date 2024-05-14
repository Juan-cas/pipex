/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:40:28 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/10 02:46:36 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"


void malloc_error_check(char *str)
{
	if (!str)
		exit(1);
}

void num_error_check(int i)
{
	if (i == -1)
		exit(1);
}

void fd_read_error_check(char *file)
{
	int i;

	i = open(file, O_RDONLY);
	if (i == -1)
		exit(1);
	else close(i);
}