/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:15:28 by bwong             #+#    #+#             */
/*   Updated: 2023/04/01 23:45:51 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// https://github.com/wertarbyte/coreutils/blob/master/src/env.c
// https://man7.org/linux/man-pages/man1/env.1p.html application use
/*
       been specified to use exit code 127 if an error occurs so that
       applications can distinguish ``failure to find a utility'' from
       ``invoked utility exited with an error indication''. The value
       127 was chosen because it is not commonly used for other
       meanings
*/
//Prints the env complete list of environment variables
int	ft_env(t_command *cmd)
{
	char	**exec;
	int		result;
	size_t	i;

	exec = cmd->exec;
	result = 127;
	if (!key_search("PATH"))
		print_error("env: ", exec[0], ": no such file or directory.");
	else if (!exec[1] || !*exec[1])
	{
		i = -1;
		while (cmd->envp[++i])
			printf("%s\n", cmd->envp[i]);
		result = 0;
	}
	return (result);
}
