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
	int		count;

	if (x == 0)
		return (ft_putchar_fd('0', 1), 1);
	count = vm_fill_hex(buffer, x, format);
	vm_write_hex(buffer, count);
	return (count);
}

int	vm_print_ptr(va_list *lst)
{
	char			buffer[20];
	unsigned long	x;
	int				count;

	x = (unsigned long)va_arg(*lst, void *);
	if (x == 0)
		return (ft_putstr_fd("(nil)", 1), 5);
	count = vm_fill_hex(buffer, x, 0);
	ft_putstr_fd("0x", 1);
	vm_write_hex(buffer, count);
	return (count + 2);
}
