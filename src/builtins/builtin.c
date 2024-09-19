/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:43:48 by bwong             #+#    #+#             */
/*   Updated: 2023/03/26 19:57:38 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//https://tldp.org/LDP/abs/html/internal.html
//exit :  exit the shell as a whole
//cd & unset update the environment 
//variables in both child & parent
void	exec_builtin_parent(t_command *cmd)
{
	if (!ft_strncmp (cmd->exec_path, "cd\0", 3))
		g_minishell.exit_code = ft_cd(cmd->exec);
	else if (!ft_strncmp (cmd->exec_path, "export\0", 7))
		g_minishell.exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp (cmd->exec_path, "unset\0", 6))
		g_minishell.exit_code = ft_unset(cmd->exec);
	else if (!ft_strncmp (cmd->exec_path, "exit\0", 5))
		g_minishell.exit_code = ft_exit(cmd->exec);
	free_envp(cmd);
	create_exec_envp(cmd);
}

void	exec_builtin_child(t_command *cmd)
{
	if (!ft_strncmp (cmd->exec_path, "env\0", 4))
		g_minishell.exit_code = ft_env(cmd);
	else if (!ft_strncmp (cmd->exec_path, "export\0", 7))
		g_minishell.exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp (cmd->exec_path, "echo\0", 5))
		g_minishell.exit_code = ft_echo(cmd->exec);
	else if (!ft_strncmp (cmd->exec_path, "pwd\0", 4))
		g_minishell.exit_code = ft_pwd(cmd->exec);
}
