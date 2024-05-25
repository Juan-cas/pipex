/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:29:36 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/25 17:47:58 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"


void infile_outfile_check(t_env *commands, char **argv, int i)
{

	commands->infile = ft_substr(argv[1], 0, ft_strlen(argv[1]));
	malloc_error_check(commands->infile);
//	can_open_file(commands, 1);
	commands->outfile = ft_substr(argv[i -  1], 0, ft_strlen(argv[i - 1]));
	malloc_error_check(commands->outfile);
//	can_open_file(commands, 2);
}