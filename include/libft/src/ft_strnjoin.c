/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:54:39 by bwong             #+#    #+#             */
/*   Updated: 2023/03/05 18:07:02 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	join_args(int number, va_list list, char **result)
{
	char	*buf;
	char	*aux;
	int		i;

	i = 0;
	while (i < number)
	{
		buf = va_arg(list, char *);
		if (i == 0)
			*result = ft_strdup(buf);
		else
		{
			aux = ft_strjoin(*result, buf);
			if (*result)
				free(*result);
			*result = aux;
		}
		i++;
	}
}

char	*ft_strnjoin(int number, ...)
{
	char	*result;
	va_list	list;

	if (number == 0)
		return (NULL);
	va_start(list, number);
	result = NULL;
	join_args(number, list, &result);
	va_end(list);
	return (result);
}
