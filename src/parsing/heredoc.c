/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:14:21 by bwong             #+#    #+#             */
/*   Updated: 2023/03/16 13:44:53 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//https://phoenixnap.com/kb/bash-heredoc
// heredoc: redirect the output of a command to a file
//  prompted for input
// then the input is written to the file when the command is executed
// keep prompting the user until it finds the delimiter 
//done in loop byusing readline
// if EOF is found -> error
// fd is invaid -> error
// https://man7.org/linux/man-pages/man2/wait.2.html
// WEXITSTATUS : returns the exit status of the child
// WIFEXITED : returns true if the child terminated normally
int	heredoc(char *name)
{
	int	pid;
	int	fd[2];
	int	wstatus;

	if (pipe(fd) == -1)
		return (heredoc_error(NULL));
	pid = fork();
	if (pid == -1)
		return (heredoc_error(NULL));
	if (!pid)
	{
		close(fd[0]);
		write_to_pipe(ft_strdup(name), &fd[1]);
	}
	get_heredoc_parent_signal();
	close(fd[1]);
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 130)
		return (heredoc_error(fd));
	return (fd[0]);
}
