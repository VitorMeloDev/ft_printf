/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:20:22 by vfreitas          #+#    #+#             */
/*   Updated: 2026/05/27 12:35:59 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*source;	

	dst = dest;
	source = src;
	i = 0;
	if (dst <= source)
	{
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			dst[n] = source[n];
		}
	}
	return (dest);
}
