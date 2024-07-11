/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_childs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:35:56 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/10 19:43:32 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static void	middle_childs(char **commands, t_env *information,
							int fd[2][2], char **envp)
{
	char	*binary_location;

	binary_location = path_tester(information->paths, commands[0]);
	pipe_redirect(fd[MAIN_PIPE][FD_READ], STDIN_FILENO);
	pipe_redirect(fd[AUX_PIPE][FD_WRITE], STDOUT_FILENO);
	fd_closer(fd[0]);
	fd_closer(fd[1]);
	executor(binary_location, commands, envp);
}

void	middle_childs_birther(t_env *information, int fd[2][2], char **envp)
{
	int	j;
	int	i;
	int	pid;

	i = 0;
	j = information->arg_counter - 4;
	while (j--)
	{
		fd_swap(fd);
		build_extra_pipe(fd[1]);
		++i;
		pid = child_birth();
		if (pid == 0)
			middle_childs(information->lst_commands[i], information, fd, envp);
		fd_closer(fd[0]);
	}
	fd_swap(fd);
}
