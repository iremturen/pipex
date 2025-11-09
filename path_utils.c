/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:27:14 by ituren            #+#    #+#             */
/*   Updated: 2025/11/09 14:23:20 by iremturen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **find_path(char *envp[])
{
    int     i;
    char    *path;
    char    **paths;

    if (!envp || !*envp)
        return (NULL);
    i = 0;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
        i++;
    if (!envp[i])
        return (NULL);
    path = ft_strdup(envp[i] + 5);
    if (!path)
        return (NULL);
    paths = ft_split(path, ':');
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
        length = ft_strlen(paths[i]) + ft_strlen(cmd) + 2;
        path = malloc(length);
        if (!path)
            return (NULL);
        ft_strlcpy(path, paths[i], length);
        ft_strlcat(path, "/", length);
        ft_strlcat(path, cmd, length);

        if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
            return path;

        free(path);
        i++;
    }
    return NULL;
}

