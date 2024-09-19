/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:41:31 by bwong             #+#    #+#             */
/*   Updated: 2023/04/14 19:03:17 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// everthing related to signal
void	get_heredoc_child_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, heredoc_handler);
}

void	get_heredoc_parent_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	parent_handler(int signal)
{
	if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		g_minishell.exit_code = 131;
	}
	if (signal == SIGINT)
	{
		printf("\n");
		g_minishell.exit_code = 130;
	}
}

// changes the default responses of the signals by parent shell
// avoid the signals respond to the childshell
void	exec_commands_parent_signals(void)
{
	signal(SIGQUIT, parent_handler);
	signal(SIGINT, parent_handler);
}

// changes the default signals received by specific shortcuts
// to avoid that these signals will respond to the parent shell,
// instead of the current.
void	exec_commands_child_signals(void)
{
	signal(SIGINT, interrupt_handler);
	signal(SIGQUIT, quit_handler);
}
