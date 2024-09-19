/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:49:33 by bwong             #+#    #+#             */
/*   Updated: 2023/03/24 15:17:16 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//add a new t_command cmd to the back of the linked list

void	add_cmd_back(t_command *cmd)
{
	t_command	*cmd_list;

	cmd_list = g_minishell.command;
	if (!cmd_list)
		g_minishell.command = cmd;
	else
	{
		while (cmd_list->next)
			cmd_list = cmd_list->next;
		cmd_list->next = cmd;
	}
}

// fill the command and redirect list by iterating through the
// //token list and analyzing the tokens
// If the token is a redirection token, 
// it will add the token to the redirect list.
// If the token is a command token, it will add the token to the command list.
// et the tokens as endpoints for the command struct.
// https://stackoverflow.com/questions/12052899/pointer-inside-round-brackets
// https://stackoverflow.com/questions/
// 29874490/expression-must-have-pointer-to-struct-or-union-error
void	set_cmd_endp(t_command **cmd, t_token **list, int *prev)
{
	t_token	**position;

	while (*list && (*list)->token_type < PIPE)
	{
		position = &(*cmd)->commands;
		if (if_redir(*prev, (*list)-> token_type))
			position = &(*cmd)->redirections;
		add_back_tkn (position, token_dup(*list));
		(*prev) = (*list)->token_type;
		(*list) = (*list)->next;
	}
	if (*list)
	{
		(*cmd)->endpoint = (*list)->token_type;
		(*prev) = (*list)->token_type;
		(*list) = (*list)-> next;
	}
}
