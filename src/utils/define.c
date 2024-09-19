/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:27 by bwong             #+#    #+#             */
/*   Updated: 2023/04/07 17:01:23 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// open the fd for the redirection and set the flags for the fd
// https://man7.org/linux/man-pages/man2/open.2.html
// O_RDONLY: read Only
// O_WRONLY: write only
// O_RDWR read and write 
// O_TRUNC: If the file already exists and is a regular file 
// and the access mode allows writing truncated to length 0.
// https://man7.org/linux/man-pages/man3/errno.3.html
void	get_fileno(int redir_type, char *filename, t_command *cmd)
{
	if (redir_type == APPEND || redir_type == REDIR_OUT)
	{
		if (cmd->fd_out != -2)
			close(cmd->fd_out);
	}
	else if (redir_type == HEREDOC || redir_type == REDIR_IN)
	{
		if (cmd->fd_in != -2)
			close(cmd->fd_in);
	}
	if (redir_type == APPEND)
		cmd->fd_out = open(filename, O_RDWR | O_APPEND | O_CREAT, 0777);
	else if (redir_type == REDIR_OUT)
		cmd->fd_out = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0777);
	else if (redir_type == REDIR_IN)
		cmd->fd_in = open(filename, O_RDONLY);
	else if (redir_type == HEREDOC)
		cmd->fd_in = heredoc(filename);
	cmd->error_number = errno;
	if (errno != 0)
		cmd->error_file = filename;
}

// check if fd is valid
// 1 is valid,0 otherwise
// exit_code 130 ->script terminated by Ctrl-C
int	check_fds(t_command *cmd)
{
	if (cmd->fd_in == -3)
	{
		g_minishell.exit_code = 130;
		return (0);
	}
	if (cmd->fd_in == -2)
		cmd->fd_in = STDIN_FILENO;
	if (cmd->fd_out == -2)
		cmd->fd_out = STDOUT_FILENO;
	return (1);
}

// define STDIN and STDOUT
// negative fd is error
int	define_redir(void)
{
	t_command	*cmd;
	t_token		*redir;

	cmd = g_minishell.command;
	while (cmd)
	{
		redir = cmd->redirections;
		while (redir)
		{
			if (cmd->fd_out != -1 || cmd->fd_in != -1)
			{
				get_fileno(redir->token_type, redir->next->token_value, cmd);
				redir = redir->next;
				redir = redir->next;
			}
		}
		if (!check_fds(cmd))
			return (0);
		cmd = cmd->next;
	}
	return (1);
}

int	define_token_type(char *token)
{
	if (!ft_strncmp(token, "<\0", 2) && ft_strncmp(token, "<<", 2))
		return (REDIR_IN);
	if ((!ft_strncmp(token, ">\0", 2)
			|| !ft_strncmp(token, ">|", 2)) && ft_strncmp(token, ">>", 2))
		return (REDIR_OUT);
	if (!ft_strncmp(token, "|", 1))
		return (PIPE);
	if (!ft_strncmp(token, ">>", 2))
		return (APPEND);
	if (!ft_strncmp(token, "<<", 2))
		return (HEREDOC);
	else
		return (WORD);
}
