/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:28:09 by bwong             #+#    #+#             */
/*   Updated: 2023/04/03 20:59:49 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "termcap.h"

static char	*return_msg(char *key)
{
	print_error("path: ", key, ": Is a directory.");
	g_minishell.exit_code = 126;
	return (NULL);
}

int	is_exec(char *exec)
{
	if (exec[0] && exec[0] == '.' && exec[1] && exec[1] == '/')
		return (1);
	else if (exec[0] == '/' && (!exec[1] || exec[1] == '/'))
		return (0);
}

char	*get_cmd_path(t_command *cmd)
{
	char		*path;
	struct stat	file_stat;

	if (!*cmd->exec)
		return (NULL);
	if (cmd->exec_path)
		free(cmd->exec_path);
	if (stat(cmd->exec[0], &file_stat) == 0 && !is_exec(cmd->exec[0]))
		return (return_msg(cmd->exec[0]));
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
