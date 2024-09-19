/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:10:44 by bwong             #+#    #+#             */
/*   Updated: 2023/03/27 17:16:20 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parser(void)
{
	start_tokenization();
	if (if_grammar_valid())
		return (0);
	command_table();
	return (1);
}

t_parser	*init_parser(void)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
	{
		free_minishell();
		exit(12);
	}
	parser->input = NULL;
	parser->tokens = NULL;
	return (parser);
}

// first initialize the global structure with the envp 
// parameter's list (converted into a hashtable)
// point all structures to NULL
void	init_shell(char **envp)
{
	char	*env_str;

	env_str = *envp;
	g_minishell.envp = init_hastable(env_str);
	send_to_hashtable(envp);
	g_minishell.parser = NULL;
	g_minishell.command = NULL;
	g_minishell.exit_code = 0;
}
