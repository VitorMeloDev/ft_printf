/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:10:59 by vfreitass         #+#    #+#             */
/*   Updated: 2026/06/10 16:36:10 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_input(const char *str, va_list *lst)
{
	if (*str == '%')
		return (ft_putchar_fd('%', 1), 1);
	if (*str == 'c')
		return (ft_putchar_fd(va_arg(*lst, int), 1), 1);
	else if (*str == 's')
		return (vm_print_string(lst));
	else if (*str == 'd')
		return (vm_print_int(lst));
	else if (*str == 'i')
		return (vm_print_int(lst));
	else if (*str == 'u')
		return (vm_print_uint(lst));
	else if (*str == 'p')
		return (vm_print_ptr(lst));
	else if (*str == 'x')
		return (vm_print_hex(va_arg(*lst, unsigned int), 0));
	else if (*str == 'X')
		return (vm_print_hex(va_arg(*lst, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += check_input(++str, &args);
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
