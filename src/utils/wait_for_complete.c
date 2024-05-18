/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_complete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:06 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/16 03:57:43 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void wait_for_children(t_env *information)
{
	int i;
	int status;
	int check_status;
	int max_wait_attempts;

	max_wait_attempts = 10;
	i = information->arg_counter - 2;
	while (i && max_wait_attempts > 0)
	{
		check_status = waitpid(-1, &status, 0);
		if (check_status < 0)
		{
			perror("waitpid failed");
			exit(1);
		}
		else if (check_status == 0)
			max_wait_attempts--;
		i--;
	}
	if (max_wait_attempts == 0)
	{
		perror("timeout waiting for child process.\n");
		exit(1);
	}
}