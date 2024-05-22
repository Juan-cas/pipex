/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative_or_absolute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:42:06 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/22 04:28:08 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int relative_or_absolute(char const *command)
{
	if (!command)
		return (-1);
	if (command[0] == '.' && command[1] == '/')
		return (1);
	if (command[0] == '/')
		return (1);
	else
		return (0);
}