/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:40:24 by vfreitass         #+#    #+#             */
/*   Updated: 2026/06/12 00:40:24 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

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
    //unsigned int x = 10;
    //int *ptr = &x;
    //ft_printf("Sua %% nota é %c! %s Com isso voce tem %u no endereço: %p\n", 'A', "Meus parabens!", x, ptr);
    //printf("Sua %% nota é %c! %s Com isso voce tem %u no endereço: %p", 'A', "Meus parabens!", x, ptr);

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

    /*char            c;
    char            *str;
    int             n;
    unsigned int    u;
    unsigned int    *ptr_u;

    c = 'A';
    str = "Meus parabens!";
    n = -42;
    u = 48879;
    ptr_u = &u;

    printf("\n===== %%c =====\n");
    printf("printf    : [%c]\n", c);
    ft_printf("ft_printf : [%c]\n", c);

    printf("\n===== %%s =====\n");
    printf("printf    : [%s]\n", str);
    ft_printf("ft_printf : [%s]\n", str);

    printf("\n===== %%d =====\n");
    printf("printf    : [%d]\n", n);
    ft_printf("ft_printf : [%d]\n", n);

    printf("\n===== %%i =====\n");
    printf("printf    : [%i]\n", n);
    ft_printf("ft_printf : [%i]\n", n);

    printf("\n===== %%u =====\n");
    printf("printf    : [%u]\n", u);
    ft_printf("ft_printf : [%u]\n", u);

    printf("\n===== %%x =====\n");
    printf("printf    : [%x]\n", u);
    ft_printf("ft_printf : [%x]\n", u);

    printf("\n===== %%X =====\n");
    printf("printf    : [%X]\n", u);
    ft_printf("ft_printf : [%X]\n", u);

    printf("\n===== %%p =====\n");
    printf("printf    : [%p]\n", ptr_u);
    ft_printf("ft_printf : [%p]\n", ptr_u);

    printf("\n===== Ponteiros =====\n");
    printf("&u        : %p\n", &u);
    printf("ptr_u     : %p\n", ptr_u);
    printf("*ptr_u    : %u\n", *ptr_u);

    printf("\n===== %% =====\n");
    printf("printf    : [%%]\n");
    ft_printf("ft_printf : [%%]\n");

    printf("\n===== Casos Limite =====\n");
    printf("\n%%u com 0\n");
    printf("printf    : [%u]\n", 0U);
    ft_printf("ft_printf : [%u]\n", 0U);

    printf("\n%%x com 0\n");
    printf("printf    : [%x]\n", 0U);
    ft_printf("ft_printf : [%x]\n", 0U);

    printf("\n%%X com 0\n");
    printf("printf    : [%X]\n", 0U);
    ft_printf("ft_printf : [%X]\n", 0U);

    printf("\n%%p com NULL\n");
    printf("printf    : [%p]\n", NULL);
    ft_printf("ft_printf : [%p]\n", NULL);

    printf("\n%%s com string vazia\n");
    printf("printf    : [%s]\n", "");
    ft_printf("ft_printf : [%s]\n", "");
    
    int a;
    int b;

    a = printf("%x\n", 48879);
    b = ft_printf("%x\n", 48879);

    printf("printf retornou    : %d\n", a);
    printf("ft_printf retornou : %d\n", b);

    printf("[%s]\n", NULL);
    ft_printf("[%s]\n", NULL);*/

    int a;
    int b;

    a = printf(
        "[%c][%s][%d][%u][%x][%p]\n",
        'A',
        "Hello",
        -42,
        42U,
        48879,
        &a);

    b = ft_printf(
        "[%c][%s][%d][%u][%x][%p]\n",
        'A',
        "Hello",
        -42,
        42U,
        48879,
        &a);

    printf("printf    = %d\n", a);
    printf("ft_printf = %d\n", b);
    return (0);
}