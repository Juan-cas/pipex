/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:39:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/30 23:46:37 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_PIPEX_H
#define PIPEX_PIPEX_H

#include "./lib/libft/libft.h"
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define fd_r 0
#define fd_w 1



// Structure for enviroment
typedef struct enviroment
{
	char				*infile;
	char				**paths;
	char				*outfile;
	char				***lst_commands;
	char				**tempmatrix;
	int 				arg_counter;
	struct enviroment	*next;
} t_env;

//parsing
t_env *pathfinder(char **envp, char **argv);
void init_struct(t_env *commands);

//utils
void free_matrix(char **matrix);

#endif //PIPEX_PIPEX_H
