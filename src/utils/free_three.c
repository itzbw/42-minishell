/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:07:54 by bwong             #+#    #+#             */
/*   Updated: 2023/03/17 13:22:07 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//free the entire t_parser struct
//clearing the token's list and the input string
void	free_parser(void)
{
	if (!g_minishell.parser)
		return ;
	if (g_minishell.parser->input)
		free(g_minishell.parser->input);
	if (g_minishell.parser->tokens)
		free_tokens(&g_minishell.parser->tokens);
	free(g_minishell.parser);
	g_minishell.parser = NULL;
}

// l184: Clear the history list by deleting all of the entries
void	free_minishell(void)
{
	if (g_minishell.envp)
		free_hashtable();
	if (g_minishell.parser)
		free_parser();
	if (g_minishell.command)
		free_command();
	rl_clear_history();
}
