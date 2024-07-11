/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_complete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:06 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/11 19:03:01 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"
#include <errno.h>

void	wait_for_children(t_env *information)
{
	int	i;
	int	status;
	int	check_status;

	i = information->arg_counter - 2;
	while (i--)
	{
		check_status = waitpid(-1, &status, 0);
		if (check_status == 0)
			break ;
	}
}
