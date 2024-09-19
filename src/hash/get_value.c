/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:15:27 by bwong             #+#    #+#             */
/*   Updated: 2023/04/02 17:43:48 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// get the value of the variable content 
char	*get_value(char *value_variable)
{
	char	*value;
	int		i;

	if (!ft_strchr(value_variable, '='))
		return (NULL);
	i = 0;
	while (value_variable[i] != '=')
		i++;
	value = ft_strdup(&value_variable[++i]);
	return (value);
}
