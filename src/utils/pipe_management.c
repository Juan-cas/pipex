/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:39:42 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/24 17:58:54 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void build_extra_pipe(int *fd)
{
	static int i = 0;

	i++;
	if (pipe(fd) == -1)
	{
		ft_putstr_fd("the pipe # ", 2);
		ft_putnbr_fd(i, 2);
		perror(" has failed, please try again\n");
		exit(1);
	}
}

void double_pipe(int fd[2][2])
{
	static int i = 0;

	i++;
	if (pipe(fd[0]) == -1)
	{
		ft_putstr_fd("the set of pipes # ", 2);
		ft_putnbr_fd(i, 2);
		perror(" has failed, please try again\n");
		exit(1);
	}
	if (pipe(fd[1]) == -1)
	{
		ft_putstr_fd("the set of pipes # ", 2);
		ft_putnbr_fd(i, 2);
		perror(" has failed, please try again\n");
		exit(1);
	}
}

void pipe_redirect(int redirector_fd, int redirected_fd)
{
	static int i = 0;

	i++;
	if (dup2(redirector_fd, redirected_fd) == -1)
	{
		ft_putstr_fd("the dup # ", 2);
		ft_putnbr_fd(i, 2);
		perror(" failed to execute, please try again\n");
		exit(1);
	}
}

