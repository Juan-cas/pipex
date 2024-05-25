/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 04:18:06 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/25 17:29:15 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void executor(char *binary_location, char **commands, char **envp)
{
	if (execve(binary_location, commands, envp) == -1)
	{
		perror("the execve has failed please check parameters\n");
		exit(1);
	}
}