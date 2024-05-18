/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_birth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:33:05 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/18 02:43:29 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static void middle_childs(char **commands, t_env *information, int *fd, char **envp)
{
	char *binary_location;

	binary_location = path_tester(information->paths, commands[0]);
	pipe_redirect(fd[fd_read], STDIN_FILENO);
	pipe_redirect(fd[fd_write], STDOUT_FILENO);
	fd_closer(fd, 0, 0);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

void middle_childs_birther(t_env *information, int *fd, char **envp)
{
	int j;
	int i;
	int pid;

	i = 0;
	j = information->arg_counter - 4;
	while (j--)
	{
		i++;
		pid = child_birth();
		pipe(fd);
		if (pid == 0)
			middle_childs(information->lst_commands[i], information, fd, envp);
	}
}

int child_birth(void)
{
	int child_id;

	child_id = fork();
	if (child_id == -1)
		exit(1);
	return (child_id);
}