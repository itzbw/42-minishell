/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:18:48 by bwong             #+#    #+#             */
/*   Updated: 2023/03/17 11:43:49 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// what is pipe?
//https://www.quora.com/What-is-a-pipe-in-terms-of-shell-in-Unix
// https://www.youtube.com/watch?v=bKzonnwoR2I
// opens all necessary pipes by the previously defined PIPE endpoints
//determines the correct fd for input and output 
//l34  Resource temporarily unavailable

void	open_pipes(void)
{
	t_command	*cmd;

	cmd = g_minishell.command;
	while (cmd)
	{
		if (cmd->endpoint == PIPE)
		{
			if (pipe(cmd->fd_pipe) == -1)
			{
				free_minishell();
				exit(11);
			}
			cmd->fd_out = cmd->fd_pipe[1];
			cmd->is_piped = 1;
			cmd->next->fd_in = cmd->fd_pipe[0];
			cmd->next->is_piped = 1;
		}
		cmd = cmd->next;
	}
}

void	write_to_pipe(char *limiter, int *fd)
{
	char	*line;
	int		len;

	get_heredoc_child_signal();
	line = readline("> ");
	len = ft_strlen(limiter);
	while (1)
	{
		if (!line)
			printf("minishell: warning: here-doc delimited by %s\n", limiter);
		if (!line || (!ft_strncmp(limiter, line, len) && !line[len]))
			break ;
		write(*fd, line, ft_strlen(line));
		write(*fd, "\n", 1);
		free(line);
		line = readline ("> ");
	}
	free(line);
	close(*fd);
	free(limiter);
	exit(0);
}
