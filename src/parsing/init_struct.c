/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:09:23 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/10 20:03:59 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../pipex.h"


void init_struct(t_env *commands)
{
	commands->infile = NULL;
	commands->paths = NULL;
	commands->outfile = NULL;
	commands->lst_commands = NULL;
	commands->arg_counter = 0;
	commands->tempmatrix = NULL;
	commands->lst_commands = ft_calloc(3, sizeof(char ***));
}