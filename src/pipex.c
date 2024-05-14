/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:53:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/13 22:39:36 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
static void first_child(char **commands, t_env *infomation, int *fd, char **envp)
{
	char *binary_location;
	int inputfd;

	binary_location = path_tester(infomation->paths, commands[0]);
	inputfd = open(infomation->infile, O_RDONLY);
	num_error_check(inputfd);
	if (dup2(fd[fd_r], inputfd) == -1)
		exit(1);
	if (dup2(fd[fd_w], STDOUT_FILENO) == -1)
		exit(1);
	close(fd[fd_r]);
	close(fd[fd_w]);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

static void last_child(char **commands, t_env *information, int *fd, char **envp)
{
	int outputfd;
	char *binary_location;

	binary_location = path_tester(information->paths, information->lst_commands[1][0]);
	outputfd = open(information->outfile,  O_CREAT | O_TRUNC | 0644);
	num_error_check(outputfd);
	if (dup2(fd[fd_r], STDIN_FILENO) == -1)
		exit(1);
	if (dup2(outputfd, STDOUT_FILENO) == -1)
		exit(1);
	close(fd[fd_w]);
	close(fd[fd_r]);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

void pipex(t_env *commands, char **envp)
{
	int fd[2];
	int child_id;

	if (pipe(fd) == -1)
		exit(1);
	child_id = child_birth();
	if (child_id == 0)
		first_child(commands->lst_commands[0], commands, fd, envp);
	child_id = child_birth();
	if (child_id == 0)
		last_child(commands->lst_commands[1], commands, fd, envp);
	else
	{
		close(fd[0]);
		close(fd[1]);
	}
}
