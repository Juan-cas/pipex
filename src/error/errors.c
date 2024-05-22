/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:40:28 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/22 05:25:56 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void failed_executer()
{
	perror("Error, missing ./ for executable or / for path");
	exit (1);
}

void can_open_file(t_env *commands, int flag)
{
	if (flag == 1)
	{
		if (access(commands->infile, F_OK |W_OK) == -1)
		{
			perror("please check the permissions of the infile");
			exit(1);
		}
		else if (access(commands->infile, F_OK) == -1)
		{
			perror("infile doesn't exist, please check name.");
			exit(1);
		}

	}
	else if (flag == 2)
	{
		if (access(commands->outfile, F_OK) == 0)
		{
			if (access(commands->outfile, W_OK) == -1)
			{
				perror("Error, check outfile write permissions.");
				exit(1);
			}
		}
	}
}
void malloc_error_check(char const *str)
{
	if (!str)
	{
		perror("Malloc failed, please try again.");
		exit(1);
	}
}

static void open_error_check(int fd, int i)
{
	if (i == 1)
	{
		if (fd == -1)
		{
			perror("Error, please check the infile permissions");
			exit(1);
		}
	}
	else {
		if (fd == -1) {
			perror("Error, please check the permissions of the outfile");
		}
	}
}

int fd_open_and_check_error(char *file, int flag)
{
	int fd;

	if (flag == 0)
	{
		fd = open(file, O_RDONLY);
		open_error_check(fd, 1);
		return (fd);
	}
	if (flag == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		open_error_check(fd, 2);
		return (fd);
	}
	exit(1);
}