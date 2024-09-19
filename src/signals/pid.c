/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:05:20 by bwong             #+#    #+#             */
/*   Updated: 2023/03/17 11:44:18 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//wait for the child processes to finish
// WIFEXITED : returns true if the child terminated normally
// WEXITSTATUS : returns the exit status of the child

void	wait_pid(int pid[MAX_PID], int id)
{
	int	max_id;
	int	wstatus;

	if (id == -1)
		return ;
	max_id = id;
	id = -1;
	wstatus = 0;
	while (++id <= max_id)
		waitpid (pid[id], &wstatus, 0);
	if (WIFEXITED(wstatus))
		g_minishell.exit_code = WEXITSTATUS(wstatus);
}

void	check_pid(t_command **cmd, pid_t pid[MAX_PID], int id)
{
	if (pid[id] == -1)
	{
		free_minishell();
		exit(11);
	}
	if (pid[id] == 0)
		exec_child(*cmd);
}
