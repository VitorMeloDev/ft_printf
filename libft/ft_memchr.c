/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:43:54 by vfreitas          #+#    #+#             */
/*   Updated: 2026/05/27 12:51:23 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*v;

	i = 0;
	v = s;
	while (i < n)
	{
		if (v[i] == (unsigned char)c)
			return ((void *)&v[i]);
		i++;
	}
	return (NULL);
}
