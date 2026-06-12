/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:52:33 by vfreitas          #+#    #+#             */
/*   Updated: 2026/05/26 13:09:43 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total;
	void			*ptr;
	unsigned char	*s;

	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	s = (unsigned char *)ptr;
	i = 0;
	while (i < total)
	{
		s[i] = 0;
		i++;
	}
	return (ptr);
}
