/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:16 by bwong             #+#    #+#             */
/*   Updated: 2023/04/13 12:30:57 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// check if the variable to export already exist in the env
// if yes -> replace the value
// if not -> add the value to the env 
// if the export is local, add to env
void	check_env(char *key, char *value)
{
	int	location;

	location = get_location(key);
	if (location == -1)
		insert_hash(key, value, GLOBAL);
	else if (location == GLOBAL && value)
		sub_hash(key, value);
	else if (location == LOCAL)
		export_hash(key, GLOBAL);
}

// https://www.man7.org/linux/man-pages/man1/export.1p.html 
// Sets environment variables
// Environmental
// variables are exported in it as child processes
// The existing environment
// variables are not affected.
// If a variable already exists in the env list, substitute it
// If it exists in the local list,
// remove it from  local list and add it to the env
// If no operator "=" is
// found in the argument, nothing will be done but no error will be printed

static int	invalid_var_name(char *key)
{
	if (if_num_first(key) || ft_cap_num(key))
		return (1);
	return (0);
}

static void	deal_values(char *value, char *exec, char *key)
{
	value = get_value(exec);
	check_env(key, value);
}

static int	return_msg(char *key, int i, char *str)
{
	print_error("export:`", key, str);
	free(key);
	return (i);
}

int	ft_export(char **exec)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	check_input(exec);
	while (exec[++i])
	{
		key = get_key(exec[i]);
		if (!key || key[0] == '\0')
			key = ft_strdup(exec[i]);
		if (if_option(key))
			return (return_msg(key, 2, "\': not a valid option."));
		if (invalid_var_name(key))
			return (return_msg(key, 1, "\': not a valid identifier."));
		else
			deal_values(value, exec[i], key);
	}
	return (0);
}
