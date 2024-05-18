/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:39:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/18 02:12:53 by juan-cas         ###   ########.fr       */
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
#include <sys/types.h>
#include <stdlib.h>

#define fd_read 0
#define fd_write 1
#define main_pipe 0
#define aux_pipe 1


// Structure for enviroment
typedef struct enviroment
{
	char				*infile;
	char				**paths;
	char				*outfile;
	char				***lst_commands;
int 				arg_counter;
} t_env;

//Main function:
void pipex(t_env *commands, char **envp);
void pipex_bonus(t_env *commands, char **envp);

//parsing
t_env *pathfinder(char **envp, char **argv);
void init_struct(t_env *commands, char **argv);

//utils
int child_birth(void);
void free_matrix(char **matrix);
int fd_open_and_check_error(char *file, int flag);
void free_struct(t_env *commands);
char *path_tester(char **matrix, char *command);
char	*append(char *s1, char const *s2);
void wait_for_children(t_env *information);
void middle_childs_birther(t_env *information, int *fd, char **envp);
void pipe_redirect(int asdqwes, int redirector_fd);
void fd_closer(int *fd, int flag, int opened_file);
void build_extra_pipe(int *fd);

//Errors
void num_error_check(int i);
void malloc_error_check(char *str);

#endif //PIPEX_PIPEX_H
