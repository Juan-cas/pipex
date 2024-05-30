/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:39:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/28 06:30:41 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_PIPEX_H
#define PIPEX_PIPEX_H

#ifndef BONUS
#define BONUS 0
#endif
#include "./lib/libft/libft.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>

#define fd_read 0
#define fd_write 1
#define main_pipe 0
#define aux_pipe 1

typedef struct enviroment
{
	char				*infile;
	char				**paths;
	char				*outfile;
	char				***lst_commands;
int 				arg_counter;
} t_env;

//Main function:
void pipex(t_env *information, char **envp);
void pipex_bonus(t_env *information, char **envp);

//parsing
t_env *pathfinder(char **envp, char **argv);
void init_struct(t_env *information, char **argv);
void free_matrix(char **matrix);
void free_struct(t_env *information);
char *path_tester(char **matrix, char *command);
char	*append(char *s1, char const *s2);
int relative_or_absolute(char const *command);
void failed_executer();

//utils
int child_birth(void);
void wait_for_children(t_env *information);
void middle_childs_birther(t_env *information, int fd[2][2], char **envp);
void fd_closer(int fd[2]);
void build_extra_pipe(int *fd);
void pipe_redirect(int redirector_fd, int redirected_fd);
void infile_outfile_check(t_env *information, char **argv, int i);
void fd_swap(int fd[2][2]);
void fd_closer_with_file(int fd[2], int opened_fd);

//Errors
void malloc_error_check(char const *str);
void there_is_no_path();
int open_infile(char *file);
int open_outfile(char *file);
void executor(char *binary_location, char **commands, char **envp);

#endif //PIPEX_PIPEX_
