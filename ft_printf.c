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
    ft_printf("Sua nota é %c! %s", 'A', "Meus parabens!");
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
    ft_putchar_fd('\n', 1);
    va_end(args);
    return (0);
}

void check_input(const char *str, va_list *lst)
{
    if (*str == '%')
        return ;
    if (*str == 'c')
        return ft_putchar_fd(va_arg(*lst, int), 1);
    else if (*str == 's')
        return ft_putstr_fd(va_arg(*lst, char *), 1);
}