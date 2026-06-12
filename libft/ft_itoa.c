/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:54:16 by marvin            #+#    #+#             */
/*   Updated: 2026/06/03 15:15:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norminet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:00:00 by norminet          #+#    #+#             */
/*   Updated: 2026/06/03 15:00:00 by norminet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	vm_get_int_lenght(long nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*num;
	int		size;

	nb = n;
	size = vm_get_int_lenght(nb);
	num = malloc(sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
	if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
	}
	num[size] = '\0';
	if (nb == 0)
		num[0] = '0';
	while ((nb > 0 && size > 0))
	{
		num[size - 1] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (num);
}
