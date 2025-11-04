/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:48:49 by ituren            #+#    #+#             */
/*   Updated: 2025/11/04 16:43:37 by iremturen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_check(int argc, char **argv, char *envp[])
{
	int	fd;

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

char	**parse_command(const char *command)
{
	char	**cmd;

	cmd = ft_split(command, ' ');
	return (cmd);
}

void	execute_commands(char const *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		child_process(pipefd, argv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(pipefd, argv, envp);
	}
}

int	main(int argc, char const *argv[], char *envp[])
{
	error_check(argc, argv, envp);
	execute_commands(argv, envp);
	return (0);
}
