/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_grammar_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:04:39 by bwong             #+#    #+#             */
/*   Updated: 2023/03/20 13:39:15 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// check if the list of tokens is in the correct order to execute
//pipe , redir , quotation mark

int	if_grammar_valid(void)
{
	t_token		*token_list;
	int			i;

	i = 0;
	token_list = g_minishell.parser->tokens;
	while (token_list)
	{
		if (!if_pipe_valid (token_list, i)
			|| !if_redir_valid (token_list)
			|| !if_quotes_valid (token_list))
			return (0);
		token_list = token_list->next;
		i++;
	}
	return (1);
}
