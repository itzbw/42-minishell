/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:54:39 by bwong             #+#    #+#             */
/*   Updated: 2023/04/14 18:00:57 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*mall(char *str)
{
	int		len;
	int		i;
	char	*cp;

	i = 0;
	len = ft_strlen(str);
	cp = malloc(sizeof(char) * len + 1);
	while (str[i] != '\0')
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ccat;
	int		len_s1;
	int		len_s2;

	if (!s1 && s2)
		return (mall((char *)s2));
	if (!s2 && s1)
		return (mall((char *)s1));
	if (!s1 && !s2)
		return (NULL);
	len_s1 = (ft_strlen((char *)s1));
	len_s2 = (ft_strlen((char *)s2));
	ccat = malloc((len_s1) + (len_s2) + 1 * sizeof(char));
	if (!ccat)
		return (NULL);
	ft_bzero(ccat, 0);
	ft_strlcpy(&ccat[0], s1, len_s1 + 1);
	ft_strlcpy(&ccat[len_s1], s2, len_s2 + 1);
	return (ccat);
}
