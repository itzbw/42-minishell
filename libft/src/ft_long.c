/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:22:29 by bwong             #+#    #+#             */
/*   Updated: 2023/03/24 14:22:34 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_long(char *str)
{
	int		i;
	int		neg;
	long	value;

	i = 0;
	value = 0;
	neg = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (value > 922337203685477580 || (value == 922337203685477580
				&& ((!neg && str[i] - '0' > 7) || (neg && str[i] - '0' > 8))))
			return (0);
		value = (value * 10) + str[i++] - '0';
	}
	while (ft_space(str[i]))
		i++;
	return (str[i] == '\0');
}
