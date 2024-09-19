/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_no_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:20:05 by bwong             #+#    #+#             */
/*   Updated: 2023/03/29 21:22:13 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	if_option(char *key)
{
	if (key[0] == '-')
		return (1);
	return (0);
}

int	if_num_first(char *key)
{
	if (ft_isdigit(key[0]))
		return (1);
	return (0);
}

//if invalid but _ char is valid
//for unset and export variables
int	if_no_meta(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if ((!ft_isalnum(key[i]) && key[i] != '_') || key[i] == '-'
			|| key[i] == '.' || key[i] == '{' || key[i] == '}'
			|| key[i] == '*' || key[i] == '#' || key[i] == '@' || key[i] == '!'
			|| key[i] == '^' || key[i] == '~' || key[i] == '\"' || key[i] == '|'
			|| key[i] == '$' || key[i] == '\'' || key[i] == ';' || key[i] == '&'
			|| key[i] == '=' || key[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
