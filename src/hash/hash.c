/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:55:22 by bwong             #+#    #+#             */
/*   Updated: 2023/04/04 15:05:44 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// what is hashtable? https://www.tutorialspoint.com/
// data_structures_algorithms/hash_data_structure.htm
// https://powershellexplained.com/2016-11-06-powershell-hashtable-
// everything-you-wanted-to-know-about/#what-is-a-hashtable
// A hashtable is a data structure much like an array, 
// except you store each value (object) using a key. 
// It is a basic key/value store. First, 
// we create an empty hashtable.
// Once you add your values to the hashtable, you can pull them back out 
// using that same key (instead of using a numeric 
// index like you would have for an array).
// Hash Table is a data structure which stores data 
// in an associative manner. In a hash table, data is stored in an array 
// format, where each data value has its own unique index value. 
// Access of data becomes very fast if we know the index of the desired data.
//Thus, it becomes a data structure in which insertion 
//and search operations are very fast irrespective of the size of the data. 
//Hash Table uses an array as a storage medium and uses hash technique to 
//generate an index where an element is to be inserted or is to be located from.
//djb2  http://www.cse.yorku.ca/~oz/hash.html
// set a variable called `hash` to the value 5381 
// and subsequently multiply it by 33 (or (hash << 5) + hash)
// then sdd the ASCII value of the current character
// Iterating hashtables
// The first thing to notice is that if you pipe your hashtable, 
// the pipe treats it like one object
unsigned long int	hash_function(char *key, unsigned int size)
{
	unsigned long int	hash;
	unsigned int		i;

	hash = 5381;
	i = 0;
	while (key && key[i])
	{
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return (hash % size);
}

//Hard coded variables created in case executable is run with env ignored
//Open to better ideas ^^

void	make_hashes(char key_w[], char value_w[])
{
	char	*key;
	char	*value;

	key = ft_strdup(key_w);
	value = ft_strdup(value_w);
	insert_hash(key, value, GLOBAL);
}

// Takes the list of env variable inserts them into the hash table
// varaibes : The list of environment variables
// https://www.gnu.org/software/bash/manual/html_node/Bash-Variables.html

static char	*update_shlvl(void)
{
	int		num;
	char	*value;

	num = ft_atoi(getenv("SHLVL"));
	num++;
	value = ft_itoa(num);
	return (value);
}

void	send_to_hashtable(char **variables)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (variables[i])
	{
		key = get_key(variables[i]);
		if (!ft_strncmp(key, "SHLVL", 5))
			value = update_shlvl();
		else
			value = get_value(variables[i]);
		insert_hash(key, value, GLOBAL);
		i++;
	}
	make_hashes("UID", "1000");
	if (!key_search("OLDPWD"))
	{
		key = ft_strdup("OLDPWD");
		value = NULL;
		insert_hash(key, value, GLOBAL);
	}
}

//allocate memory for hashtable
//initiate value
//size 100 (should i add more?) // allocates it dynamically
// plus 1 for the UID, maybe not really needed...
//return table

t_hashtable	*init_hastable(char *env_str)
{
	t_hashtable	*table;
	int			i;

	i = 0;
	while (env_str[i])
		i++;
	table = malloc(sizeof(t_hashtable));
	if (!table)
	{
		free_minishell();
		exit (12);
	}
	table->size = i + 1;
	table->count = 0;
	table->list = ft_calloc(sizeof(t_hashpair *), i + 1);
	if (!table->list)
	{
		free_minishell();
		exit (12);
	}
	return (table);
}
