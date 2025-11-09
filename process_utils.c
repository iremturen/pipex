
#include "pipex.h"

void	child1_process(int *pipefd, const char **argv, char **envp) //infile → command1 → pipe yaz
{
	int		fd_in;
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		print_error("Cannot open infile\n", 1);
	cmd = parse_command(argv[2]);
	paths = find_path(envp);
	if (!paths)
		print_error("Path not found\n", 127);
	cmd_path = find_command(paths, cmd[0]);
	if (!cmd_path)
		print_error("Command not found\n", 127);
	dup2(fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd_in);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(cmd_path, cmd, envp);
	print_error("Command execution failed\n", 127);
}

void	child2_process(int *pipefd, const char **argv, char **envp) //pipe oku → command2 → outfile yaz
{
	int		fd_out;
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		print_error("Cannot open outfile\n", 1);
	cmd = parse_command(argv[3]);
	paths = find_path(envp);
	if (!paths)
		print_error("Path not found\n", 127);
	cmd_path = find_command(paths, cmd[0]);
	if (!cmd_path)
		print_error("Command not found\n", 127);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(pipefd[1]);
	close(pipefd[0]);
	execve(cmd_path, cmd, envp);
	print_error("Command execution failed\n", 127);
}
