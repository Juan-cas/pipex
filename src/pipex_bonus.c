/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:29:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/11 19:13:09 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	first_child(char **commands,
						t_env *infomation, int fd[2][2], char **envp)
{
	char	*binary_location;
	int		inputfd;

	binary_location = path_tester(infomation->paths, commands[0]);
	inputfd = open_infile(infomation->infile);
	pipe_redirect(inputfd, STDIN_FILENO);
	pipe_redirect(fd[AUX_PIPE][FD_WRITE], STDOUT_FILENO);
	fd_closer(fd[MAIN_PIPE]);
	fd_closer(fd[AUX_PIPE]);
	executor(binary_location, commands, envp);
}

static void	last_child(char **commands,
						t_env *information, int fd[2][2], char **envp)
{
	int		outputfd;
	char	*binary_location;

	binary_location = path_tester(information->paths, commands[0]);
	outputfd = open_outfile(information->outfile);
	pipe_redirect(fd[MAIN_PIPE][FD_READ], STDIN_FILENO);
	pipe_redirect(outputfd, STDOUT_FILENO);
	fd_closer(fd[0]);
	executor(binary_location, commands, envp);
}

void	pipex_bonus(t_env *information, char **envp)
{
	int	i;
	int	pid;
	int	fd[2][2];

	i = 0;
	while (information->lst_commands[i])
		i++;
	build_extra_pipe(fd[MAIN_PIPE]);
	build_extra_pipe(fd[AUX_PIPE]);
	pid = child_birth();
	if (pid == 0)
		first_child(information->lst_commands[0], information, fd, envp);
	fd_closer(fd[MAIN_PIPE]);
	middle_childs_birther(information, fd, envp);
	pid = child_birth();
	if (pid == 0)
		last_child(information->lst_commands[i - 1], information, fd, envp);
	fd_closer(fd[MAIN_PIPE]);
	wait_for_children(information);
}
