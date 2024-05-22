/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:26:07 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/18 07:44:50 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"



int main(int argc, char **argv, char **envp)
{
	t_env *commands;

	if (argc == 5 && BONUS == 0)
	{
		commands = pathfinder(envp, argv);
		pipex(commands, envp);
	}
	else if (argc >= 5 && BONUS == 1)
	{
		commands = pathfinder(envp, argv);
		pipex_bonus(commands, envp);
	}
	else
	{
		perror("please check number of arguments");
		exit(1);
	}
	free_struct(commands);
	free(commands);
	return 0;
}