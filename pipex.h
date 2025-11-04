# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char **find_path(char *envp[]);
char *find_command(char **paths, const char *cmd);
void	ft_putendl_fd(char *s, int fd);
void *print_error(char *msg, int exit_code);
char	**parse_command(const char *command);
void	child_process(int *pipefd, char **argv, char **envp);
void	parent_process(int *pipefd, char **argv, char **envp);