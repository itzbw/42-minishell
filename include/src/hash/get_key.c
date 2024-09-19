/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:14:48 by bwong             #+#    #+#             */
/*   Updated: 2023/04/04 14:49:26 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// get the key which is variable name 

char	*get_key(char *key_variable)
{
	char	*key;
	int		i;

	i = 0;
	if (!ft_strchr(key_variable, '='))
		return (NULL);
	while (key_variable[i] != '=')
		i++;
	key = malloc(sizeof(char) * (++i));
	ft_bzero(key, 0);
	if (!key)
		return (NULL);
	ft_strlcpy(key, key_variable, i);
	return (key);
}
