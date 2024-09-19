/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_pipe_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:06:34 by bwong             #+#    #+#             */
/*   Updated: 2023/04/13 12:33:55 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//check pipe position or follow by cmd

int	if_pipe_valid(t_token *token, int pos)
{
	if (token->token_type == PIPE)
	{
		if (pos == 0 || !token->next
			|| !ft_strncmp(token->next->token_value, "|", 1))
		{
			print_error("syntax:", NULL, " : unexpected token.");
			g_minishell.exit_code = 2;
			return (0);
		}
	}
	return (1);
}
