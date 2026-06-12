/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 22:22:37 by vfreitass         #+#    #+#             */
/*   Updated: 2026/06/11 22:22:37 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	vm_get_uint_length(unsigned int nb)
{
	int	size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	nb;
	char			*num;
	int				size;

	nb = n;
	size = vm_get_uint_length(nb);
	num = malloc(sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
	num[size] = '\0';
	if (nb == 0)
		num[0] = '0';
	while (nb > 0 && size > 0)
	{
		num[size - 1] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (num);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	value;

	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	value = (n % 10) + '0';
	write(fd, &value, 1);
}
