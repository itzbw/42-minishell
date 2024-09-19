/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:50:31 by bwong             #+#    #+#             */
/*   Updated: 2023/04/13 12:35:55 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//https://github.com/wertarbyte/coreutils/blob/master/src/echo.c

//print the args following "echo" and a \n
// -n omits the trailing \n 
// check if there 'n' , yes -> 1, no -> 0
// print the args and if -n is 0 , print a \n 

int	check_option(char *option)
{
	int	i;
	int	counter;

	i = 1;
	counter = ft_strlen(option);
	while (option[i] && option[i] == 'n')
		i++;
	if (counter == i)
		return (1);
	else
		return (0);
}

int	check_if_option(char *exec)
{
	if (exec[0] == '-')
	{
		if (check_option(exec))
			return (1);
		return (0);
	}
	return (0);
}

int	ft_echo(char **exec)
{
	int	n_flag;
	int	i;

	i = 1;
	n_flag = 0;
	while (exec && exec[i] && check_if_option(exec[i]))
	{
		n_flag++;
		i++;
	}
	while (exec && exec[i])
	{
		printf("%s", exec[i]);
		if (exec[i] && exec[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (n_flag == 0)
		printf("\n");
	return (0);
}
