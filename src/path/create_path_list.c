/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:29:44 by bwong             #+#    #+#             */
/*   Updated: 2023/03/17 17:30:06 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**create_path_list(void)
{
	char	**path;
	char	*temp;

	path = NULL;
	temp = key_search("PATH");
	if (temp)
		path = ft_split (temp, ':');
	return (path);
}
