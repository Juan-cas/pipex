/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:42:50 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/30 22:30:58 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static char *w_path(char **envp)
{
	int i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return envp[i];
		}
	}
	return (NULL);
}

static char *path_tester(char **matrix, char *command)
{
	int i;
	char *order;

	i = -1;
	while(matrix[++i])
	{
		order = ft_strjoin(matrix[i], command);
		if (access(order, F_OK) == 0)
			return (order);
		free(order);
	}
	return (NULL);
}

static void path_fixer(t_env *commands, int counter)
{
	char *str;
	char *final_str;

	str = path_tester(commands->paths, commands->tempmatrix[0]);
	final_str = ft_substr(str, 0, ft_strlen(str));
	free(commands->tempmatrix[0]);
	commands->tempmatrix[0] = final_str;
}

static void command_splitter(t_env *commands, char **argv)
{
	int	i;
	int j;

	j = 0;
	commands->lst_commands = malloc( commands->counter * sizeof(char **));
	i = 0;
	while (++i <= commands->counter)
	{
		commands->tempmatrix = ft_split(argv[i], ' ');
		if (path_tester(commands->paths, commands->tempmatrix[0]))
			path_fixer(commands, j++);
		else
			free_matrix(commands->tempmatrix);
	}
}

t_env *pathfinder(char **envp, char **argv)
{
	char	*str;
	int		i;
	t_env	*commands;

	init_struct(commands);
	i = 1;
	while (argv[++i]);

	str = w_path(envp);
	commands->arg_counter = i;
	commands->infile = ft_substr(argv[1], 0, ft_strlen(argv[1]));
	commands->outfile = ft_substr(argv[i], 0, ft_strlen(argv[i]));
	commands->paths = ft_split(str + 5, ':');
	command_splitter(commands, argv);
	return (commands);
}