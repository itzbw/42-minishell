/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:43:08 by bwong             #+#    #+#             */
/*   Updated: 2023/03/30 15:17:06 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_all_fds(void)
{
	t_command	*cmd;

	cmd = g_minishell.command;
	while (cmd)
	{
		close_fd(cmd, BOTH);
		cmd = cmd->next;
	}
}

// dup2: duplicate a file descriptor
// the file descriptor newfd is adjusted 
// so that it no refers to the same open file description as oldfd.
// execve - execute program referred to by pathname
// the program that is currently being run by the calling
//process to be replaced with a new program, with newly initialized
//stack, heap, and data segments.
// int execve(const char *pathname, char *const argv[], char *const envp[]);
// errno - number of last error
//  is significant only when the return value of the call indicated an error
// -1 from most system calls; -1
// or NULL from most library functions
// The value of errno is never set to zero
// by any system call or library function

void	exec_child(t_command *cmd)
{
	if (cmd->fd_in > 2)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out > 2)
		dup2(cmd->fd_out, STDOUT_FILENO);
	close_all_fds();
	if (if_builtin(cmd))
		exec_builtin_child(cmd);
	else
	{
		exec_commands_child_signals();
		execve(cmd->exec_path, cmd->exec, cmd->envp);
		return_error(cmd->exec[0], errno);
	}
	free_minishell();
	exit(g_minishell.exit_code);
}
