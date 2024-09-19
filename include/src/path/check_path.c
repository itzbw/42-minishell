/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:28:54 by bwong             #+#    #+#             */
/*   Updated: 2023/03/17 17:29:23 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Check if a file exists and is executable
void	check_path(t_command *cmd, char **path_list, char **path)
{
	char	*curr_path;
	int		i;

	i = -1;
	while (path_list[++i])
	{
		curr_path = ft_strnjoin (3, path_list[i], "/", cmd->exec[0]);
		if (access(curr_path, F_OK) == 0)
		{
			*path = curr_path;
			break ;
		}
		free(curr_path);
	}
	free_path(path_list);
}
