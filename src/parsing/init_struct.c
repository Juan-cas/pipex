/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:09:23 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/30 23:46:40 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../pipex.h"


void init_struct(t_env *commands)
{
	commands->infile = NULL;
	commands->paths = NULL;
	commands->outfile = NULL;
	commands->lst_commands = NULL;
	commands->next = NULL;
	commands->arg_counter = 0;
	commands->tempmatrix = NULL;
}