/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:07:54 by bwong             #+#    #+#             */
/*   Updated: 2023/03/17 13:22:07 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// everything related to free
void	free_node(t_hashpair *curr)
{
	free(curr->hash_key);
	free(curr->hash_value);
	free(curr);
	curr = NULL;
}

void	free_hashpair(t_hashpair *node)
{
	t_hashpair	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node;
		node = tmp->next;
		free(tmp->hash_key);
		free(tmp->hash_value);
		free(tmp);
	}
}

void	free_export(char **export)
{
	int	i;

	i = -1;
	while (export[++i])
		free(export[i]);
	free(export);
}

void	free_hashtable(void)
{
	t_hashtable	*hashtable;
	size_t		i;

	i = 0;
	hashtable = g_minishell.envp;
	while (i < hashtable->size)
	{
		free_hashpair(hashtable->list[i]);
		i++;
	}
	free(hashtable->list);
	free(hashtable);
}

// read through the path and free each element
void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
