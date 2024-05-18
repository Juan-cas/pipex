/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:42:50 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/16 03:35:08 by juan-cas         ###   ########.fr       */
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

char *path_tester(char **matrix, char *command)
{
	int i;
	char *order;
	int checker;

	i = -1;
	if (access(command, F_OK) == 0)
		return (ft_substr(command, 0, ft_strlen(command)));
	while(matrix[++i])
	{
		order = append(matrix[i], command);
		if (!order)
			exit(1);
		checker = access(order, F_OK);
		if (checker == 0)
			return (order);
		free(order);
	}
	return (NULL);
}

static void command_splitter(t_env *commands, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 2;

	while (i < commands->arg_counter)
	{
		commands->lst_commands[j] = ft_split(argv[i], ' ');
		if (!commands->lst_commands[j])
			exit(1);
		j++;
		i++;
	}
}

t_env *pathfinder(char **envp, char **argv)
{
	char	*str;
	int		i;
	t_env	*commands;

	commands = malloc(sizeof(t_env));
	if (!commands)
		exit(1);
	init_struct(commands, argv);
	i = 1;
	while (argv[++i]);

	if (envp)
	{
		str = w_path(envp);
		commands->paths = ft_split(str + 5, ':');
		if (!commands->paths)
			exit(1);
	}

	commands->arg_counter = i - 1;
	commands->infile = ft_substr(argv[1], 0, ft_strlen(argv[1]));
	malloc_error_check(commands->infile);
	commands->outfile = ft_substr(argv[i -  1], 0, ft_strlen(argv[i - 1]));
	malloc_error_check(commands->outfile);
	command_splitter(commands, argv);
	return (commands);
}