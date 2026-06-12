/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:18:00 by vfreitas          #+#    #+#             */
/*   Updated: 2026/05/26 18:32:54 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*v;
	size_t			i;

	i = 0;
	v = s;
	while (i < n)
	{
		v[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
