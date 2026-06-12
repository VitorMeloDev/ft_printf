/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 09:57:43 by vfreitas          #+#    #+#             */
/*   Updated: 2026/05/27 10:11:27 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			size;
	size_t			i;
	unsigned char	v;

	v = (unsigned char)c;
	size = 0;
	while (s[size] != '\0')
		size++;
	i = 0;
	while (i <= size)
	{
		if (s[size - i] == v)
			return ((char *)&s[size - i]);
		i++;
	}
	return (NULL);
}
