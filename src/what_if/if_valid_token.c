/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:35:59 by bwong             #+#    #+#             */
/*   Updated: 2023/04/14 19:51:03 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// identify if the current char is a new token to be split
// input: original string
// prev : prev char index in the string
// return 1 : new token found, otherwise 0
int	if_valid_token(const char *input, size_t i, size_t prev)
{
	if (!input[i] || !i)
		return (1);
	if (if_in_quotes(input, i))
		return (0);
	if (ft_strchr("|<> ", input[i]))
	{
		if (i - prev == 1)
		{
			if ((input[i] == '<' && input[prev] == '<')
				|| (input[i] == '>' && input[prev] == '>')
				|| (input[i] == ' ' && input[prev] == ' '))
				return (0);
		}
		if (ft_space(input[i]) && ft_space(input[i - 1]))
			return (0);
		return (1);
	}
	if (i > 0 && ft_strchr("|<> ", input[i - 1]))
		return (1);
	return (0);
}
