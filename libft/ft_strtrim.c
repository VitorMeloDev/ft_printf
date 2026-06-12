/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:04:18 by marvin            #+#    #+#             */
/*   Updated: 2026/06/01 15:04:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	vm_verify_ishere(char c, char const *src)
{
	while (*src != '\0')
	{
		if (c == *src)
			return (1);
		src++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] != '\0' && vm_verify_ishere(s1[i], set) == 1)
		i++;
	while (len > i && vm_verify_ishere(s1[len - 1], set) == 1)
		len--;
	str = ft_substr(s1, i, len - i);
	return (str);
}
