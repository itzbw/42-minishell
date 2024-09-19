/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:13:46 by bwong             #+#    #+#             */
/*   Updated: 2023/03/24 15:19:30 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//adds a new pair to the end of the list

void	bk_hash(t_hashpair **list, char *key, char *value, int atr)
{
	t_hashpair	*new;
	t_hashpair	*tmp;

	new = malloc (sizeof(t_hashpair));
	if (!new)
		return ;
	new->hash_key = ft_strdup(key);
	new->hash_value = ft_strdup(value);
	new->attribute = atr;
	new->next = NULL;
	tmp = *list;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
