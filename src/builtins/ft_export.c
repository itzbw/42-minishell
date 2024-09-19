/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:16 by bwong             #+#    #+#             */
/*   Updated: 2023/04/15 15:54:45 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Substitute a new variable at the end of the hashtable's correct hashlist
void	sub_hash(char *key, char *value)
{
	t_hashtable	*table;
	t_hashpair	*list;
	char		*sub;
	int			i;

	table = g_minishell.envp;
	i = hash_function(key, table->size);
	list = table->list[i];
	while (ft_strncmp(list->hash_key, key, ft_strlen(key)))
		list = list->next;
	sub = list->hash_value;
	if (value)
		list->hash_value = ft_strdup(value);
	free(sub);
	free(key);
	free(value);
}

//Export a variable set locally to the enviroment
void	export_hash(char *key, int new_attribute)
{
	t_hashtable	*table;
	t_hashpair	*list;
	int			i;

	table = g_minishell.envp;
	i = hash_function (key, table->size);
	list = table->list[i];
	while (ft_strncmp(list->hash_key, key, ft_strlen(key)))
		list = list->next;
	list->attribute = new_attribute;
	free(key);
}

// print list of env variable if no args when export is called
// "declare -x"
// https://www.tutorialspoint.com/unix_commands/export.htm
void	print_declarex(t_hashpair *node)
{
	if (!node->hash_value)
		printf("declare -x %s\n", node->hash_key);
	else
		printf("declare -x %s=\"%s\"\n",
			node->hash_key, node->hash_value);
}

// check if empty str args or no args
// print all env variable that are exported

void	check_input(char **exec)
{
	t_hashpair	**pair;
	t_hashpair	*node;
	size_t		i;

	if ((!exec[1] || !*exec[1]) && ft_strncmp(exec[1], "\0", 1))
	{
		i = 0;
		pair = g_minishell.envp->list;
		while (i < g_minishell.envp->size)
		{
			node = pair[i];
			while (node)
			{
				if (node->attribute == GLOBAL)
					print_declarex(node);
				node = node->next;
			}
			i++;
		}
	}
}

// Checks location where the variable is stored 
// Global table -> 0
// Local table -> 1
// not found -> -1
int	get_location(char *location_key)
{
	t_hashtable	*table;
	t_hashpair	*tmp;
	int			i;

	table = g_minishell.envp;
	i = hash_function(location_key, table->size);
	tmp = table->list[i];
	while (tmp)
	{
		if (!ft_strncmp(tmp->hash_key, location_key, ft_strlen(location_key)))
			return (tmp->attribute);
		tmp = tmp->next;
	}
	return (-1);
}
