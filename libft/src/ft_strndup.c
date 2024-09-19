/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:56:16 by bwong             #+#    #+#             */
/*   Updated: 2023/04/01 12:54:04 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*ptr;

	if (!size)
		return (NULL);
	ptr = (char *)malloc(sizeof(ptr) * size + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memcpy(ptr, s1, size);
	ptr[size] = 0;
	return (ptr);
}
