/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:29:36 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/10 19:41:28 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	infile_outfile_check(t_env *information, char **argv, int i)
{
	information->infile = ft_substr(argv[1], 0, ft_strlen(argv[1]));
	malloc_error_check(information->infile);
	information->outfile = ft_substr(argv[i - 1], 0, ft_strlen(argv[i - 1]));
	malloc_error_check(information->outfile);
}
