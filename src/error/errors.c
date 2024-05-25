/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:40:28 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/25 18:40:42 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void failed_executer()
{
	perror("Error, missing ./ for executable or / for path");
}

void malloc_error_check(char const *str)
{
	if (!str)
	{
		perror("Malloc failed, please try again.");
		exit(1);
	}
}

int fd_open_and_check_error(char *file, int flag)
{
	int fd;

	if (flag == 0)
	{
		fd = open(file, O_RDONLY);
		return (fd);
	}
	if (flag == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		return (fd);
	}
	exit(1);
}