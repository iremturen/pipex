/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:48:49 by ituren            #+#    #+#             */
/*   Updated: 2025/11/03 19:29:49 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_check(int argc, char *argv, char *envp[])
{
	int fd;
	
	if (argc != 5)
	 	print_error("Error: 4 arguments required.", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(strerror(errno), 1);
	if (access(argv[4], F_OK) == 0)
	{
		fd = open(argv[4], O_WRONLY);
		if (fd == -1)
			print_error(strerror(errno), 1);
	}	
}

char **parse_command(char  **command)
{
	char	**cmd;

	cmd = ft_split(command, ' ');
	return (cmd);
}

void	child_process()
{
	
	dup2(pipefd[1], 1);
	
	printf("merhaba\n");
	
	char buf[100];
	read(pipefd[0], buf, 5);
	
	
	// ls | cat
}

void	execute_commands(char const *argv[], char *envp[])
{
	int		pipefd[2];
	char 	**cmd1;
	char 	**cmd2;
	int		pid;

	if (pipe(pipefd) == -1)
		print_error(strerror(errno), 1);
	cmd1 = parse_command(argv[2]);
	cmd2 = parse_command(argv[3]);
		
	if (find_command(envp, cmd1))
	{
		
	}
	if (find_command(envp, cmd2))
	{
		
	}
	
	
	
}

int	main(int argc, char const *argv[], char *envp[])
{
	
	return 0;
}
