/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:28:09 by bwong             #+#    #+#             */
/*   Updated: 2023/04/14 22:18:35 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_cmd_path(t_command *cmd)
{
	char		*path;

	if (!*cmd->exec)
		return (NULL);
	if (cmd->exec_path)
		free(cmd->exec_path);
	if (if_builtin(cmd))
		path = ft_strdup(cmd->exec[0]);
	else
	{
		path = setup_path(cmd);
		if (!path)
		{
			if (!key_search("PATH"))
				cmd_error(cmd, 1);
			else
				cmd_error(cmd, 2);
		}
	}
	return (path);
}
