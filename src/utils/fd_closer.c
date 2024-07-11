/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:55:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/10 19:38:32 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	fd_closer(int fd[2])
{
	if (close(fd[FD_READ]) == -1)
	{
		perror("failed to close the pipe please try again\n");
	}
	if (close(fd[FD_WRITE]) == -1)
	{
		perror("failed to close the pipe please try again\n");
	}
}

void	fd_closer_with_file(int fd[2], int opened_fd)
{
	if (close(opened_fd) == -1)
	{
		perror("failed to close the file please try again\n");
	}
	if (close(fd[FD_READ]) == -1)
	{
		perror("failed to close the pipe please try again\n");
	}
	if (close(fd[FD_WRITE]) == -1)
	{
		perror("failed to close the pipe please try again\n");
	}
}
