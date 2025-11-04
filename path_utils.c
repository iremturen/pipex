/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:27:14 by ituren            #+#    #+#             */
/*   Updated: 2025/11/04 16:17:57 by iremturen        ###   ########.fr       */
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
	int length;

	i = 0;
	while (paths[i])
	{
		length = paths[i] + ft_strlen(cmd) + 2;
		path = malloc(length);
		if (!path)
			return (NULL);
		ft_strlcpy(path, paths[i], length);
		ft_strlcat(path, "/", length);
		ft_strlcat(path, cmd, length);
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
