/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:09:13 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/10 00:07:50 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "pipex.h"

int main(void)
{
	int fd[2];
	int pid;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		int ifd = open("input.txt", )
		char *str[4] = {
				"/bin/cat",
				"-e",
			NULL
		};
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve("/bin/cat", str, NULL);
	}
	else {
		int ofd = open("output.txt", O_WRONLY | O_CREAT, 0777);
		pid = fork();
		if (pid == 0) {
			char *str[4] = {
					"/bin/wc",
					"-l",
					NULL
			};
			dup2(fd[0], STDIN_FILENO);
			dup2(ofd, STDOUT_FILENO);
			close(fd[0]);
			close(ofd);
			close(fd[1]);
			execve("/bin/wc", str, NULL);
		} else
		{
			close(fd[0]);
			close(fd[1]);
			close(ofd);
		}
	}
	return (0);
}