/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:21:21 by bwong             #+#    #+#             */
/*   Updated: 2023/03/20 13:46:27 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//Checks if the character is a redirection 
int	if_redir(int prev, int token_type)
{
	if (token_type == REDIR_OUT || token_type == HEREDOC
		|| token_type == REDIR_IN || token_type == APPEND
		|| prev == REDIR_OUT || prev == HEREDOC
		|| prev == REDIR_IN || prev == APPEND)
		return (1);
	return (0);
}
