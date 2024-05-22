/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_birth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:33:05 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/22 08:21:05 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static void middle_childs(char **commands, t_env *information, int fd[2], char **envp)
{
	char *binary_location;

	build_extra_pipe(fd);
	binary_location = path_tester(information->paths, commands[0]);
	pipe_redirect(fd[fd_read], information->last_used_fd);
	pipe_redirect(fd[fd_write], STDOUT_FILENO);
	fd_closer(fd, 0, 0);
	if (execve(binary_location, commands, envp) == -1)
		exit(1);
}

void middle_childs_birther(t_env *information, int fd[2], char **envp)
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
		close(information->last_used_fd);
		close(fd[fd_read]);
		information->last_used_fd = fd[1];
		printf("the middle fds are %d\n", information->last_used_fd);
	}
}

int child_birth(void)
{
	int child_id;

	child_id = fork();
	if (child_id == -1)
	{
		perror("child birth failed, please try again");
		exit(1);
	}
	return (child_id);
}