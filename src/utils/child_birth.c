/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_birth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:33:05 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/24 17:53:49 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static void middle_childs(char **commands, t_env *information, int fd[2][2], char **envp)
{
	char *binary_location;

	binary_location = path_tester(information->paths, commands[0]);
	pipe_redirect(fd[main_pipe][fd_read], STDIN_FILENO);
	pipe_redirect(fd[aux_pipe][fd_write], STDOUT_FILENO);
	fd_closer(fd[0]);
	fd_closer(fd[1]);
	close(information->temp_fd);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

void middle_childs_birther(t_env *information, int fd[2][2], char **envp)
{
	int j;
	int i;
	int pid;

	i = 0;
	j = information->arg_counter - 4;
	while (j--)
	{
		build_extra_pipe(fd);
		pid = child_birth();
		if (pid == 0)
			middle_childs(information->lst_commands[++i], information, fd, envp);
		fd_closer(fd);
	}
}

int child_birth(void)
{
	int child_id;
	static int i = 0;

	i++;
	child_id = fork();
	if (child_id == -1)
	{
		ft_putstr_fd("trying to make fork # ", 2);
		ft_putnbr_fd(i, 2);
		perror(" has failed please try again\n");
		exit(1);
	}
	return (child_id);
}