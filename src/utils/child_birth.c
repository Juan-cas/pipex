/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_birth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:33:05 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/10 19:40:16 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	child_birth(void)
{
	int			child_id;
	static int	i = 0;

	i++;
	child_id = fork();
	if (child_id == -1)
	{
		perror("trying to make fork has failed please try again\n");
		exit(1);
	}
	return (child_id);
}
