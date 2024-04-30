/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:26:07 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/28 18:01:43 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"



int main(int argc, char **argv, char **envp)
{
	if (argc < 4)
		return (1);


	/* deberemos recibir los parametros, ejemplo ./pipex text.txt "cat -e" "wc -l" outfile.txt
	 * pasos a hacer, dividir los argumentos y tomar el primer archivo para el primer hijo y
	 * el ultimo archivo para el ultimo hijo. TODO: utilizar mas datos para manejar mas hijos.
	 */

	TODO: verificar que si alguno de los hijos falla los demas puedan continuar con los procesos
	con la informacion que existe (fallo debido a nombre erroneo o que no exista el comando),
	revisar si el archivo/binario tiene permisos de lectura/escritura/ejecucion y aparte si es una carpeta.


	pathfinder(envp, argv);
	correct_path = path(matrix, argv[2]);
	correct_path2 = path(matrix, argv[3]);
	int pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execv(correct_path, )
	}




	return 0;
}