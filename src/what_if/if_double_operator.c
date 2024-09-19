/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_double_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:58:15 by bwong             #+#    #+#             */
/*   Updated: 2023/03/20 13:43:21 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//check if there are double symbol
int	if_double_operator(char curr, char prev)
{
	if (curr == '|' && prev == '|')
		return (0);
	if (curr == '>' && prev == '>')
		return (0);
	if (curr == '<' && prev == '<')
		return (0);
	if (curr == '&' && prev == '&')
		return (0);
	if (curr == ' ' && prev == ' ')
		return (0);
	return (1);
}
