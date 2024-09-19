/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_eof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:10:44 by bwong             #+#    #+#             */
/*   Updated: 2023/03/20 14:44:27 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://man7.org/linux/man-pages/man3/readline.3.html
// readline will read a line from the terminal and return it, 
// using prompt as a prompt.  
// If prompt is NULL or the empty string, no prompt is issued. 

int	if_eof(char *str)
{
	if (!str)
		return (1);
	return (0);
}
