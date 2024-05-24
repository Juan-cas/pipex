/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_complete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:06 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/22 09:31:01 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"
#include <errno.h>

void wait_for_children(t_env *information)
{
	int i;
	int status;
	int check_status;

	i = information->arg_counter - 2;
	while (i--)
	{
		check_status = waitpid(-1, &status, 0);
		if (check_status == -1) {
			if (errno == ECHILD) {
				printf("No child processes to wait for.\n");
			} else {
				perror("waitpid");
			}
		} else {
			printf("Child process with PID %d changed state.\n", check_status);
			if (WIFEXITED(status)) {
				printf("Child exited with status %d.\n", WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("Child killed by signal %d.\n", WTERMSIG(status));
			} else if (WIFSTOPPED(status)) {
				printf("Child stopped by signal %d.\n", WSTOPSIG(status));
			}
		}
		if (check_status == 0)
			break ;
	}
}
