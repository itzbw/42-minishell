/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:55:31 by bwong             #+#    #+#             */
/*   Updated: 2023/03/25 17:15:17 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*token_dup(t_token *src)
{
	t_token	*dest;

	dest = malloc (sizeof(t_token));
	if (!dest)
	{
		free_minishell();
		exit(12);
	}
	dest->token_value = ft_strdup(src->token_value);
	dest->token_type = src->token_type;
	dest->next = NULL;
	return (dest);
}

// add the new t_tkn node to the back of a t_tkn list
void	add_back_tkn(t_token **list, t_token *new_token)
{
	t_token	*tmp;

	tmp = *list;
	if (!tmp)
		(*list) = new_token;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
	}
}

// split the input by spaces & add each token to the token's list
// 1. allocating memory for the token
// 2. copying the token string and size
// 3. creating a new token node
// 4. adding the new token node to the token's list
void	add_to_token_list(const char *input, size_t size)
{
	t_token	*token_list;
	char	*token;

	while (ft_space(*input))
	{
		size--;
		input++;
	}
	if (!size || !(*input))
		return ;
	token = ft_strndup(input, size);
	token_list = create_token(token, 0);
	add_back_tkn(&g_minishell.parser->tokens, token_list);
}
