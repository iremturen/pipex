/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:48:49 by ituren            #+#    #+#             */
/*   Updated: 2025/11/14 17:48:01 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_check(int argc, const char **argv)
{
	int	fd;

	if (argc != 5)
		print_error("Error: 4 arguments required.", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(strerror(errno), 1);
	close(fd);
	if (access(argv[4], F_OK) == 0)
	{
		fd = open(argv[4], O_WRONLY);
		if (fd == -1)
			print_error(strerror(errno), 1);
	}
	close(fd);
}

char	**parse_command(const char *command)
{
	char	**cmd;

	cmd = ft_split(command, ' ');
	return (cmd);
}

static void	parent_process(const char **argv, char **envp) //pipe oluşturur, forklarla çocukları yaratır
{
	int		pipefd[2]; //Pipe array → pipefd[0]=read, pipefd[1]=write
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
		print_error("Pipe error\n", 1);

	pid1 = fork(); //yeni bir process oluştur hata -1, child 0, parent PID → pozitif sayı
	if (pid1 == 0)
		child1_process(pipefd, argv, envp); //Birinci child oluşturulur → cmd1

	pid2 = fork();
	if (pid2 == 0)
		child2_process(pipefd, argv, envp); //İkinci child oluşturulur → cmd2

	close(pipefd[0]);
	close(pipefd[1]); //Parent pipe kullanmaz → kapatır
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0); //Parent her iki child bitene kadar bekler
}

int	main(int argc, char const *argv[], char *envp[])
{
	error_check(argc, argv);
	parent_process(argv, envp);
	return (0);
}
