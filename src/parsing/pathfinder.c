/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:42:50 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/10 19:37:19 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static char	*w_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i]);
		}
	}
	there_is_no_path();
	return (NULL);
}

char	*path_tester(char **matrix, char *command)
{
	int		i;
	char	*order;
	int		checker;

	i = -1;
	if (relative_or_absolute(command))
	{
		if (access(command, F_OK) == 0)
			return (ft_substr(command, 0, ft_strlen(command)));
		else
			failed_executer();
	}
	while (matrix[++i])
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

static void	command_splitter(t_env *information, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 2;
	while (i < information->arg_counter)
	{
		information->lst_commands[j] = ft_split(argv[i], ' ');
		if (!information->lst_commands[j])
			exit(1);
		j++;
		i++;
	}
}

t_env	*pathfinder(char **envp, char **argv)
{
	char	*str;
	int		i;
	t_env	*information;

	information = malloc(sizeof(t_env));
	if (!information)
		exit(1);
	init_struct(information, argv);
	i = 1;
	while (argv[i])
		i++;
	if (envp)
	{
		str = w_path(envp);
		information->paths = ft_split(str + 5, ':');
		if (!information->paths)
			exit(1);
	}
	information->arg_counter = i - 1;
	infile_outfile_check(information, argv, i);
	command_splitter(information, argv);
	return (information);
}
