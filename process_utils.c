
#include "pipex.h"

void	child_process(int *pipefd, char **argv, char **envp)
{
	char	**cmd;
	int		fd_infile;

	cmd = parse_command(argv[2]);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
		print_error("Cannot open infile.", 1);
	dup2(fd_infile, 0);
	close(fd_infile);
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	execve(cmd[0], cmd, envp);
}


void	parent_process(int *pipefd, char **argv, char **envp)
{
	char	**cmd;
	int		fd_outfile;

	cmd = parse_command(argv[3]);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
		print_error("Cannot open outfile.", 1);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd_outfile, 1);
	close(fd_outfile);
	execve(cmd[0], cmd, envp);
}
