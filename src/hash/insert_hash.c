/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:15:59 by bwong             #+#    #+#             */
/*   Updated: 2023/03/25 16:14:06 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//Inserts a new variable at the end of the hashtable's correct hashlist

void	insert_hash(char *key, char *value, int attribute)
{
	t_hashtable	*table;
	int			i;

	table = g_minishell.envp;
	i = hash_function(key, table->size);
	bk_hash(&(table->list[i]), key, value, attribute);
	table->count++;
	free(key);
	free(value);
}
