/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WYSIWYG.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:12 by bwong             #+#    #+#             */
/*   Updated: 2023/03/17 17:46:07 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// founctions with get
// create_prompt function with strdup
// describe the minishell program and the current path
char	*get_folder_path(void)
{
	char	*path;
	char	*folder;
	char	*folder_path;

	path = get_pwd();
	folder = ft_strrchr (path, '/');
	folder_path = ft_strjoin(&folder[1], "/");
	free(path);
	return (folder_path);
}
