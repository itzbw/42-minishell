/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_identifier_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:20:05 by bwong             #+#    #+#             */
/*   Updated: 2023/03/26 20:47:22 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//  It contains a list of invalid
//characters, character combinations or blanks for export names
// identifier valid -> return 1
// identifier invalid -> return 0
int	if_identifier_valid(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) || key[i] == '-' || key[i] == '.'
			|| key[i] == '{' || key[i] == '}'
			|| key[i] == '*' || key[i] == '#' || key[i] == '@' || key[i] == '!'
			|| key[i] == '^' || key[i] == '~' || key[i] == '\"' || key[i] == '|'
			|| key[i] == '$' || key[i] == '\'' || key[i] == ';' || key[i] == '&'
			|| key[i] == '=' || key[i] == ' ')
		{
			g_minishell.exit_code = 1;
			return (0);
		}
		if (key[i] == '+' && key[i + 1] != '=')
		{
			g_minishell.exit_code = 1;
			return (0);
		}
		i++;
	}
	return (1);
}
