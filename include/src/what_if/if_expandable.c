/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_expandable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:10 by bwong             #+#    #+#             */
/*   Updated: 2023/04/13 14:08:59 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// check current char is expandable
// yes if after '?' or a letter
// if followed by a digit -> won't produce an output && '$'
// also won't be treated as an ordinary character.

int	clean_count_size(char *key, char c, char d)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (key[i])
	{
		if (key[i] == c || key[i] == d)
			counter++;
		i++;
	}
	return (i - counter);
}

char	*ft_clean(char	*key, char c, char d)
{
	int		size;
	char	*new_str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	size = clean_count_size(key, c, d);
	new_str = malloc(sizeof(char) * size + 1);
	if (!new_str)
		return (NULL);
	while (key[i])
	{
		if (key[i] != c && key[i] != d)
		{
			new_str[k] = key[i];
			k++;
		}
		i++;
	}
	new_str[k] = '\0';
	return (new_str);
}

int	in_env_list(char *key)
{
	t_hashtable	*table;
	t_hashpair	*tmp;
	int			i;
	char		*new_key;

	table = g_minishell.envp;
	new_key = ft_clean(key, '$', '\"');
	i = hash_function(new_key, table->size);
	tmp = table->list[i];
	while (tmp)
	{
		if (!ft_strncmp(tmp->hash_key, new_key, ft_strlen(new_key)))
		{
			free(new_key);
			return (1);
		}
		tmp = tmp->next;
	}
	free(new_key);
	return (0);
}

int	if_expandable(char curr_char)
{
	if (ft_isalnum(curr_char) || curr_char == '_' || curr_char == '?')
		return (1);
	return (0);
}
