/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:10:44 by bwong             #+#    #+#             */
/*   Updated: 2023/04/14 19:11:22 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_minishell	g_minishell;

//https://hackernoon.com/lets-build-a-linux-shell-part-i-bz3n3vg1
//https://tiswww.case.edu/php/chet/readline/readline.html#Utility-Functions
/*
 * void rl_replace_line (const char *text, int clear_undo)
 * Replace the contents of rl_line_buffer with text. 
 * The point and mark are preserved, if possible. 
 * If clear_undo is non-zero, the undo list associated with 
 * the current line is cleared.
 * int rl_on_new_line (void)
 * Tell the update functions that we have moved onto a new (empty) line, 
 * usually after outputting a newline. 
 * void rl_redisplay (void)
 * Change what’s displayed on the screen to
 * reflect the current contents of rl_line_buffer. 
*/

void	read_a_line(void)
{
	char	*prompt;

	g_minishell.parser = init_parser();
	g_minishell.parser->input = readline("\e[91m💀️ minis(HELL)💀️:\e[0m $ ");
	if (if_eof(g_minishell.parser->input))
	{
		printf("exit\n");
		free_minishell();
		exit(0);
	}
	add_history(g_minishell.parser->input);
}

// open terminal
// opens a command prompt to the user in an infinite loop
// change the response to received signals
// clear the struct and ready for next input
// open a prompt and wait for the input
// send to parsing & execute

void	shell_loop(void)
{
	while (1)
	{
		change_signals();
		free_parser();
		free_command();
		read_a_line();
		if (!start_tokenization())
			continue ;
		start_execution();
	}
}

// first initialize the global structure with the envp 
// parameter's list (converted into a hashtable)
// point all structures to NULL

static int	init_error(int flag)
{
	if (flag == 12)
		ft_putstr_fd("Error! No environment variables detected.", 2);
	else if (flag == 1)
		ft_putstr_fd("Invalid STDIN.", 2);
	else if (flag == 2)
	{
		ft_putstr_fd("Invalid arguments.", 2);
		flag--;
	}
	return (flag);
}

int	main(int argc, char **argv, char **envp)
{
	if (!envp[0])
		exit(init_error(12));
	if (!isatty(0))
		exit(init_error(1));
	if (argc > 1 && argv)
	{
		free_minishell();
		exit(init_error(2));
	}
	init_shell(envp);
	shell_loop();
	return (0);
}
