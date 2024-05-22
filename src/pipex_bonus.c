/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:29:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/22 08:12:38 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


static void first_child(char **commands, t_env *infomation, int fd[2], char **envp)
{
	char *binary_location;
	int inputfd;

	binary_location = path_tester(infomation->paths, commands[0]);
	inputfd = fd_open_and_check_error(infomation->infile, 0);
	pipe_redirect(inputfd, STDIN_FILENO);
	pipe_redirect(fd[fd_write], STDOUT_FILENO);
	fd_closer(fd, 1, inputfd);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

static void last_child(char **commands, t_env *information, int fd[2], char **envp)
{
	int outputfd;
	char *binary_location;

	build_extra_pipe(fd);
	binary_location = path_tester(information->paths, commands[0]);
	outputfd = fd_open_and_check_error(information->outfile, 1);
	pipe_redirect(fd[fd_read], information->last_used_fd);
	pipe_redirect(outputfd, STDOUT_FILENO);
	fd_closer(fd, 1, outputfd);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

void pipex_bonus(t_env *information, char **envp)
{
	int i;
	int pid;
	int fd[2];

	i = -1;
	while (information->lst_commands[++i]);
	build_extra_pipe(fd);
	pid = child_birth();
	if (pid == 0)
		first_child(information->lst_commands[0], information, fd, envp);
	information->last_used_fd = fd[1];
	printf("fd first time = %d\n", information->last_used_fd);
	close(fd[fd_read]);
	middle_childs_birther(information, fd, envp);
	build_extra_pipe(fd);
	pid = child_birth();
	if (pid == 0)
		last_child(information->lst_commands[i - 1], information, fd, envp);
	close(information->last_used_fd);
	printf("the last fd is %d\n", fd[1]);
	fd_closer(fd, 0, 0);
	wait_for_children(information);
}