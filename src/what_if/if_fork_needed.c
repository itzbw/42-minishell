/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_fork_needed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:18:01 by bwong             #+#    #+#             */
/*   Updated: 2023/03/20 13:45:32 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// https://www.gnu.org/software/bash/manual/html_node/Bourne-Shell-Builtins.html
// checks if a builtin needs a child process
// yes-> 1 , 0 otherwise
// cd, exit, unset (in Parents needs fork)

int	if_fork_needed(t_command *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "cd\0", 3)
		|| !ft_strncmp(cmd->exec_path, "unset\0", 6)
		|| !ft_strncmp(cmd->exec_path, "exit\0", 5))
	{
		if (!cmd->is_piped)
			exec_builtin_parent(cmd);
		return (0);
	}
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7)
		&& cmd->exec[1] && *cmd->exec[1])
	{
		if (!cmd->is_piped)
			exec_builtin_parent(cmd);
		return (0);
	}
	return (1);
}
