/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:12:16 by vfreitas          #+#    #+#             */
/*   Updated: 2026/05/26 20:35:24 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;
	size_t	len_d;

	len_s = 0;
	while (src[len_s] != '\0')
		len_s++;
	len_d = 0;
	while (dst[len_d] != '\0' && len_d < size)
		len_d++;
	if (len_d == size)
		return (size + len_s);
	i = 0;
	while (src[i] != '\0' && (len_d + i) < size - 1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_s + len_d);
}
