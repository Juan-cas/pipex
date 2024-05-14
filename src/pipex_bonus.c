/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:29:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/02 02:29:12 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void first_child(char **commands, int *fd)
{
	dup2(fd[fd_r], STDOUT_FILENO);
	dup2(fd[fd_w], STDIN_FILENO);
	close(fd[fd_r]);
	close(fd[fd_w]);
	execv(commands[0], commands);
	exit(1);
}

static void middle_childs(char **commands, int *fd)
{
	//TODO: generar una nueva pipe y reasignar.
	close(fd_r);
	dup2(fd[fd_w], 1);
	close(fd[fd_w]);
	execv(commands[0], commands);
}

static void last_child(char **commands, char *outfile)
{

}
void pipex(t_env *commands)
{
	int i;
	int j;
	int pid;
	int fd[2];

	if (pipe(fd) == -1)
		exit(1);
	i = 0;
	pid = fork();
	num_error_check(pid);
	if (pid == 0)
		first_child(commands->lst_commands[i], fd);
	else
	{
		i++;
		j = commands->arg_counter - 4;
		while (j--)
			middle_childs(commands->lst_commands[i++], fd);
	}
}