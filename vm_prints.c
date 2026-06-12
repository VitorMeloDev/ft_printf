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

#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int vm_print_string(va_list *lst)
{
    char    *str;
    str = va_arg(*lst, char *);
    ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}

int vm_print_int(va_list *lst)
{
    char    *number;

    number = ft_itoa(va_arg(*lst, int));
    ft_putstr_fd(number, 1);
    return (ft_strlen(number));
}

int vm_print_uint(va_list *lst)
{
    char    *number;

    number = ft_itoa(va_arg(*lst, unsigned int));
    ft_putstr_fd(number, 1);
    return (ft_strlen(number));
}

int vm_print_hex(unsigned int x, int format)
{
    char    buffer[20];
    int i;
    int rest;
    int count;

    if (x == NULL && format == 0)
    {
        ft_putstr_fd("(nil)", 1);
        return (0);
    }
    if (x == 0)
    {
        ft_putchar_fd('0', 1);
        return (0);
    }
    i = 0;
    count = 0;
    while (x > 0)
    {
        rest = x % 16;
        if (rest < 10)
            buffer[i++] = rest + '0';
        else 
        {   
            if (format == 2)
                buffer[i++] = (rest - 10) + 'A';
            else
                buffer[i++] = (rest - 10) + 'a';
        }
        x /= 16;
    }
    if (format == 0)
        ft_putstr_fd("0x", 1);
    while (--i >= 0)
    {
        ft_putchar_fd(buffer[i], 1);
    }
    return (0);
}
