/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:24:45 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/15 23:35:58 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void free_struct(t_env *commands)
{
	int i;

	i = -1;
	free(commands->infile);
	free(commands->outfile);
	free_matrix(commands->paths);
	while (commands->lst_commands[++i])
		free_matrix(commands->lst_commands[i]);
	free(commands->lst_commands);
}