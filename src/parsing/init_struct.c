/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:09:23 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/10 19:33:52 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	init_struct(t_env *information, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		i++;
	information->infile = NULL;
	information->paths = NULL;
	information->outfile = NULL;
	information->arg_counter = 0;
	information->lst_commands = ft_calloc(i, sizeof(char ***));
}
