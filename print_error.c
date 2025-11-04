/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremturen <iremturen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:37:29 by ituren            #+#    #+#             */
/*   Updated: 2025/11/04 17:11:36 by iremturen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void *print_error(char *msg, int exit_code)
{
	ft_putendl_fd(msg, 1);
	exit(exit_code);
}