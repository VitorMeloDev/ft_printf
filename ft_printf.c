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
int check_input(const char *str, va_list *lst);

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
    //max(4, 25.100, 10, 20, 30);
    //print("ddfd", 10, 15, 12.621, 300);

    //printf("%c", NULL);
    //ft_printf("%c", NULL);
    unsigned int x = 10;
    int *ptr = &x;
    ft_printf("Sua %% nota é %c! %s Com isso voce tem %u no endereço: %p\n", 'A', "Meus parabens!", x, ptr);
    printf("Sua %% nota é %c! %s Com isso voce tem %u no endereço: %p", 'A', "Meus parabens!", x, ptr);

    //int x = 42;
    //unsigned long n = (unsigned long)&x;
    //printf("%lu\n", n);
    //printf("%lx\n", (unsigned long)&x);

    //ft_printf("%p\n", &x);
    //printf("%p\n", &x);
    //printf("%x\n", 48879);
    //ft_printf("%x\n", 48879);
    //printf("%X", 48879);
    //ft_printf("%X\n", 48879);
    //ft_printf("%p\n", &x);
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

int check_input(const char *str, va_list *lst)
{
    if (*str == '%')
        return (ft_putchar_fd('%', 1), 1);
    if (*str == 'c')
        return (ft_putchar_fd(va_arg(*lst, int), 1), 1);
    else if (*str == 's')
        return (vm_print_string(*lst));
    else if (*str == 'd')
        return (vm_print_int(*lst));
    else if (*str == 'i')
        return (vm_print_int(*lst));
    else if (*str == 'u')
        return (vm_print_uint(*lst, 1));
    else if (*str == 'p') {
        void *ptr = va_arg(*lst, void*);
        return (vm_print_hex((unsigned long)ptr, 0));
    }
    else if (*str == 'x')
        return (vm_print_hex(va_arg(*lst, unsigned int), 1));
    else if (*str == 'X')
        return (vm_print_hex(va_arg(*lst, unsigned int), 2));
    return (0);
}
