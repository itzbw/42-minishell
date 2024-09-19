/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:41:31 by bwong             #+#    #+#             */
/*   Updated: 2023/03/16 13:34:21 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// everthing related to signal

//  Handler for the SIGQUIT signal.
void	interrupt_handler(int signal)
{
	(void)signal;
	free_minishell();
	exit(130);
}

//  Handler for the SIGINT signal
// exit 131 State not recoverable

void	quit_handler(int signal)
{
	(void)signal;
	free_minishell();
	exit(131);
}

//print a new line when the user presses Ctrl+C
void	main_loop_handler(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

// change input signal to avoid sigmals to respond with parent shell
void	change_signals(void)
{
	signal(SIGINT, main_loop_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	heredoc_handler(int signal)
{
	(void)signal;
	printf("\n");
	free_minishell();
	exit(130);
}
