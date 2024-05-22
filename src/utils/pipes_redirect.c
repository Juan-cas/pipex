/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:39:42 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/20 01:43:26 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void build_extra_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("pipe failed, please try again");
		exit(1);
	}
}

void pipe_redirect(int redirector_fd, int redirected_fd)
{
	if (dup2(redirector_fd, redirected_fd) == -1)
	{
		perror("dup2 failed to execute, please try again");
		exit(1);
	}
}

