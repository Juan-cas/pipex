/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:39:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/10 21:07:49 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_PIPEX_H
#define PIPEX_PIPEX_H

#ifndef BONUS
#define BONUS 0
#endif
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
} t_env;

void pipex(t_env *commands, char **envp);

//parsing
t_env *pathfinder(char **envp, char **argv);
void init_struct(t_env *commands);

//utils
int child_birth(void);
void free_matrix(char **matrix);
void fd_read_error_check(char *file);
void free_struct(t_env *commands);
//char	**split_w_file(char const *s, char *file, char c);
char *path_tester(char **matrix, char *command);
char	*append(char *s1, char const *s2);

//Errors
void num_error_check(int i);
void malloc_error_check(char *str);

#endif //PIPEX_PIPEX_H
