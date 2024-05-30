/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:40:28 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/28 06:21:20 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void failed_executer()
{
	perror("Error, missing ./ for executable or / for path\n");
}

void malloc_error_check(char const *str)
{
	if (!str)
	{
		perror("Malloc failed, please try again.\n");
		exit(1);
	}
}