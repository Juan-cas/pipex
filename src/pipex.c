/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:53:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/28 06:28:34 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void first_child(char **commands, t_env *infomation, int *fd, char **envp)
{
	char *binary_location;
	int inputfd;

	binary_location = path_tester(infomation->paths, commands[0]);
	inputfd = open_infile(infomation->infile);
	pipe_redirect(inputfd, STDIN_FILENO);
	pipe_redirect(fd[fd_write], STDOUT_FILENO);
	fd_closer_with_file(fd, inputfd);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

static void last_child(char **commands, t_env *information, int *fd, char **envp)
{
	int outputfd;
	char *binary_location;

	binary_location = path_tester(information->paths, information->lst_commands[1][0]);
	outputfd = open_outfile(information->outfile);
	pipe_redirect(fd[fd_read], STDIN_FILENO);
	pipe_redirect(outputfd, STDOUT_FILENO);
	fd_closer_with_file(fd, outputfd);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

void pipex(t_env *commands, char **envp)
{
	int fd[2];
	int child_id;

	build_extra_pipe(fd);
	child_id = child_birth();
	if (child_id == 0)
		first_child(commands->lst_commands[0], commands, fd, envp);
	child_id = child_birth();
	if (child_id == 0)
		last_child(commands->lst_commands[1], commands, fd, envp);
	fd_closer(fd);
	wait_for_children(commands);
}
