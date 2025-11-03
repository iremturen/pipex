/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituren <ituren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:27:14 by ituren            #+#    #+#             */
/*   Updated: 2025/11/03 19:01:13 by ituren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **find_path(char *envp[])
{
	int		i;
	char	*path;
	char	**paths;
	
	i = -1;
	path = NULL;
	if (!envp || !*envp)
		return (NULL);
	while (envp[++i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);			
			break ;
		}
	}
	if (!path)
		return (free(path), NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (free(paths), NULL);
	free(path);
	return (paths);
}

char *find_command(char **paths, const char *cmd)
{
	int i;
	char *path;

	i = 0;
	while (paths[i])
	{
		path = malloc(paths[i] + ft_strlen(cmd) + 2);
		if (!path)
			return (NULL);
		ft_strlcpy(path, paths[i],ft_strlen(path));
		ft_strlcat(path, "/", 1);
		ft_strlcat(path, cmd, ft_strlen(cmd));
		if (access(path, F_OK) == 0)
		{
			if(access(path, X_OK) == 0)
				return (path);			
			else
				return (-1);
		}
		else
		{
			free(path);
			return (NULL);	
		}			
	}	
}
