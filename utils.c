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

static int	vm_get_int_lenght(unsigned int nb)
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

char	*ft_uitoa(int n)
{
	unsigned int   nb;
	char	*num;
	int		size;

	nb = n;
	size = vm_get_int_lenght(nb);
	num = malloc(sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
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

void	ft_putunbr_fd(int n, unsigned int fd)
{
	long	nb;
	char	value;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	value = (nb % 10) + '0';
	write (fd, &value, 1);
}
