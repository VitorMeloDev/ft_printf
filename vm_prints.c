/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:49:28 by vfreitass         #+#    #+#             */
/*   Updated: 2026/06/11 20:49:28 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	vm_print_string(va_list *lst)
{
	char	*str;

	str = va_arg(*lst, char *);
	if (str == NULL)
		return (ft_putstr_fd("(null)", 1), 6);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	vm_print_int(va_list *lst)
{
	char	*number;
	int		len;

	number = ft_itoa(va_arg(*lst, int));
	len = ft_strlen(number);
	ft_putstr_fd(number, 1);
	free(number);
	return (len);
}

int	vm_print_uint(va_list *lst)
{
	char	*number;
	int		len;

	number = ft_uitoa(va_arg(*lst, int));
	len = ft_strlen(number);
	ft_putstr_fd(number, 1);
	free(number);
	return (len);
}

int	vm_print_hex(unsigned int x, int format)
{
	char	buffer[20];
	int		i;
	int		count;
	int		rest;

	if (x == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0;
	while (x > 0)
	{
		rest = x % 16;
		if (rest < 10)
			buffer[i++] = rest + '0';
		else
		{
			if (format == 1)
				buffer[i++] = (rest - 10) + 'A';
			else
				buffer[i++] = (rest - 10) + 'a';
		}
		x /= 16;
	}
	count = i;
	while (--i >= 0)
		ft_putchar_fd(buffer[i], 1);
	return (count);
}

int	vm_print_ptr(va_list *lst)
{
	void			*ptr;
	char			buffer[20];
	unsigned long	x;
	int				i;
	int				count;
	int				rest;

	ptr = va_arg(*lst, void *);
	x = (unsigned long)ptr;
	if (x == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = 0;
	while (x > 0)
	{
		rest = x % 16;
		if (rest < 10)
			buffer[i++] = rest + '0';
		else
			buffer[i++] = (rest - 10) + 'a';
		x /= 16;
	}
	ft_putstr_fd("0x", 1);
	count = i + 2;
	while (--i >= 0)
		ft_putchar_fd(buffer[i], 1);
	return (count);
}
