/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_birth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:33:05 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/10 02:48:46 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int child_birth(void)
{
	int child_id;

	child_id = fork();
	if (child_id == -1)
		exit(1);
	return (child_id);
}