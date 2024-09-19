/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:51:37 by bwong             #+#    #+#             */
/*   Updated: 2023/04/13 12:31:06 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//https://github.com/wertarbyte/coreutils/blob/master/src/pwd.c
// print current working directory

int	if_tok_invalid(char *tok)
{
	if (tok[0] == '-')
		return (1);
	return (0);
}

int	ft_pwd(char **exec)
{
	char	*pwd;

	if (exec[1] && if_tok_invalid(exec[1]))
	{
		print_error("pwd:`", exec[1], "\': invalid option.");
		return (2);
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free(pwd);
		pwd = key_search("PWD");
		printf("%s\n", pwd);
	}
	else
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	return (0);
}
