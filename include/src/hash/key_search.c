/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:07:31 by bwong             #+#    #+#             */
/*   Updated: 2023/03/20 14:13:11 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// search the value of the key from the HASHTABLE

char	*key_search(char *key)
{
	t_hashtable	*table;
	t_hashpair	*tmp;
	int			i;

	table = g_minishell.envp;
	i = hash_function(key, table->size);
	tmp = table->list[i];
	while (tmp)
	{
		if (!ft_strncmp(tmp->hash_key, key, ft_strlen(key)))
			return (tmp->hash_value);
		tmp = tmp->next;
	}
	return (NULL);
}
