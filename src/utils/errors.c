/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:40:28 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/14 21:40:55 by juan-cas         ###   ########.fr       */
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

int fd_open_and_check_error(char *file, int flag)
{
	int i;

	if (flag == 0)
	{
		i = open(file, O_RDONLY);
		num_error_check(i);
		return (i);
	}
	if (flag == 1)
	{
		i = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		num_error_check(i);
		return (i);
	}
	exit(1);
}