/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:21:27 by bwong             #+#    #+#             */
/*   Updated: 2023/04/14 22:29:40 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
void	remove_empty_var(t_token *token, char *remove)
{
	int		len;
	int		i;
	int		k;
	char	*new_token;
	char	*token_cp;

	i = 0;
	k = 0;
	len = ft_strlen(ft_clean(token->token_value, '\'', '\"')) - ft_strlen(remove);
	token_cp = ft_clean(token->token_value, '\'', '\"');
	new_token = malloc(sizeof(char) * len + 1);
	if (!new_token)
		return ;
	while (token_cp[i] && token_cp[i] == remove[i])
			i++;
	while (token_cp[i + k] != '\0')
	{
		new_token[k] = token_cp[k + i];
		k++;
	}
	new_token[k] = '\0';
	free(token_cp);
	free(token->token_value);
	token->token_value = ft_strdup(new_token);
	printf("the new value of token:%s\n", token->token_value);
	free(new_token);
}
*/

/*char	*create_prompt(void)
{
	char	*name;
	char	*folder;
	char	*sign;
	char	*prompt;

	name = ft_strdup("💀️ MINIS(HELL)💀️:");
	folder = get_folder_path();
	sign = ft_strdup (" $ ");
	prompt = ft_strnjoin (5, RED, name, CYAN, sign, RESET);
	free(name);
	free(folder);
	free(sign);
	return (prompt);
}
*/
