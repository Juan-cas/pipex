/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:09:23 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/16 04:08:54 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../pipex.h"


void init_struct(t_env *commands, char **argv)
{
	int i;

	i = 0;
	while (argv[++i]);
	commands->infile = NULL;
	commands->paths = NULL;
	commands->outfile = NULL;
	commands->arg_counter = 0;
	commands->lst_commands = ft_calloc(i, sizeof(char ***));
}