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

#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int ft_printf(const char *str, ...);
void check_input(const char *str, va_list *lst);
int vm_lonhex(unsigned long  x, int fd);

int max(int num_args, ...)
{
    int i = 0;
    va_list args;
    va_start(args, num_args);

    while (i++ < num_args)
    {
        int x = va_arg(args, int);
        printf("x: %d\n", x);
    }
    va_end(args);
    return (0);
}

void    print(char *placeholders, ...)
{
    int i = 0;
    int num_args = strlen(placeholders);
    va_list args;
    va_start(args, placeholders);

    while (i < num_args)
    {
        if (placeholders[i] == 'd')
        {
            int x = va_arg(args, int);
            printf("%d\n", x);
        }
        else if (placeholders[i] == 'f')
        {
            double x = va_arg(args, double);
            printf("%f\n", x);
        }
        i++;
    }
    va_end(args);
}

int main(void)
{
    printf("%x\n", 0);
    ft_printf("%x\n", 0);

    printf("%X\n", 0);
    ft_printf("%X\n", 0);

    printf("%x\n", 15);
    ft_printf("%x\n", 15);

    printf("%X\n", 15);
    ft_printf("%X\n", 15);

    printf("%x\n", 16);
    ft_printf("%x\n", 16);

    printf("%X\n", 16);
    ft_printf("%X\n", 16);
    return (0);
}

int ft_printf(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
            check_input(++str, &args);
        else
            ft_putchar_fd(*str, 1);
        str++; 
    }
    va_end(args);
    return (0);
}

void check_input(const char *str, va_list *lst)
{
    if (*str == '%')
        return ft_putchar_fd('%', 1);
    if (*str == 'c')
        return ft_putchar_fd(va_arg(*lst, int), 1);
    else if (*str == 's')
        return ft_putstr_fd(va_arg(*lst, char *), 1);
    else if (*str == 'd')
        return ft_putnbr_fd(va_arg(*lst, int), 1);
    else if (*str == 'i')
        return ft_putnbr_fd(va_arg(*lst, int), 1);
    else if (*str == 'u')
        return ft_putunbr_fd(va_arg(*lst, unsigned int), 1);
    else if (*str == 'p') {
        void *ptr = va_arg(*lst, void*);
        return vm_lonhex((unsigned long)ptr, 0);
    }
    else if (*str == 'x')
        return vm_lonhex(va_arg(*lst, unsigned int), 1);
    else if (*str == 'X')
        return vm_lonhex(va_arg(*lst, unsigned int), 2);
}

int vm_lonhex(unsigned long  x, int format)
{
    char    buffer[20];
    int i;
    int rest;
    int count;

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