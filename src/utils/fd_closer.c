/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:55:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/17 22:59:05 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void fd_closer(int *fd, int flag, int opened_file)
{
	if (flag == 1)
		close(opened_file);
	close(fd[fd_read]);
	close(fd[fd_write]);
}