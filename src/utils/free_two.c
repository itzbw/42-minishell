/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:07:54 by bwong             #+#    #+#             */
/*   Updated: 2023/03/24 18:39:35 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// free the memory allocated for the execution envp
void	free_envp(t_command *cmd)
{
	int	i;

	i = -1;
	while (cmd->envp[++i])
		free(cmd->envp[i]);
	free(cmd->envp);
	cmd->envp = NULL;
}

// freeing double pointer string and freeing the string itself
void	free_expansion(char **str, char *next)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (next)
		free(next);
}

// free all the memory allocated by the execution list
void	free_exec_list(char **exec)
{
	int	i;

	i = -1;
	if (!exec)
		return ;
	while (exec[++i])
		free(exec[i]);
	free(exec);
}

// free the entire t_cmd struct
//clearing the command and redirect token's list,
//the exec array and the exec_path string
void	free_command(void)
{
	t_command	*curr;
	t_command	*tmp;

	curr = g_minishell.command;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free_tokens(&tmp->commands);
		free_tokens(&tmp->redirections);
		free_exec_list(tmp->exec);
		if (tmp->envp)
			free_envp(tmp);
		if (tmp->exec_path)
			free(tmp->exec_path);
		free(tmp);
	}
	g_minishell.command = NULL;
}

void	free_tokens(t_token **tokens)
{
	t_token	*token;
	t_token	*temp;

	token = *tokens;
	while (token)
	{
		temp = token;
		token = token->next;
		free(temp->token_value);
		free(temp);
	}
	*tokens = NULL;
}
