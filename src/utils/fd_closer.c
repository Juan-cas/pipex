/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:55:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/25 17:30:47 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void fd_closer(int fd[2])
{
	if (close(fd[fd_read]) == -1)
	{
		perror("failed to close the pipe please try again\n");
		exit (1);
	}
	if (close(fd[fd_write]) == -1)
	{
		perror("failed to close the pipe please try again\n");
		exit (1);
	}
}


void fd_closer_with_file(int fd[2], int opened_fd)
{
	if (close(opened_fd) == -1)
	{
		perror("failed to close the file please try again\n");
		exit(1);
	}
	if (close(fd[fd_read]) == -1)
	{
		perror("failed to close the pipe please try again\n");
		exit (1);
	}
	if (close(fd[fd_write]) == -1)
	{
		perror("failed to close the pipe please try again\n");
		exit (1);
	}
}