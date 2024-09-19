/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_in_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:59:49 by bwong             #+#    #+#             */
/*   Updated: 2023/03/20 13:41:12 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// check if the current strin is between an even number of quotes
int	if_in_quotes(const char *input, size_t index)
{
	int	i;
	int	in_quotes;

	i = 0;
	in_quotes = -1;
	while (i < (int)index)
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			if (in_quotes == -1)
				in_quotes = (int)i;
			else if (in_quotes != -1 && input[in_quotes] == input[i])
				in_quotes = -1;
		}
		i++;
	}
	if (in_quotes != -1)
		return (1);
	return (0);
}
