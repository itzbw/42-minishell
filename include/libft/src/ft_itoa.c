/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:15:30 by bwong             #+#    #+#             */
/*   Updated: 2023/03/26 19:11:57 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	num_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_loop(char *str, int len, long num)
{
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	num;
	int		len;

	num = nbr;
	len = num_len(num);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str = ft_loop(str, len, num);
	return (str);
}
