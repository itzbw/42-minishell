/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_redir_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:15:45 by bwong             #+#    #+#             */
/*   Updated: 2023/04/01 23:49:58 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// check operator (in, out, append, heredoc) + next token is word
// if invalid -> print error msg

int	if_redir_valid(t_token *token)
{
	if (token->token_type == REDIR_IN || token->token_type == APPEND
		|| token->token_type == REDIR_OUT || token->token_type == HEREDOC)
	{
		if (!token->next)
		{
			print_error("syntax: ", NULL, "unexpected token.");
			g_minishell.exit_code = 2;
			return (0);
		}
		else if (token->next->token_type != WORD)
		{
			print_error("syntax: ", NULL, "unexpected token.");
			g_minishell.exit_code = 2;
			return (0);
		}
	}
	return (1);
}
