/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:06:29 by vfreitass         #+#    #+#             */
/*   Updated: 2026/06/12 20:06:29 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	max_test(int num_args, ...)
{
	int		i;
	int		x;
	va_list	args;

	i = 0;
	va_start(args, num_args);
	while (i++ < num_args)
	{
		x = va_arg(args, int);
		printf("x: %d\n", x);
	}
	va_end(args);
	return (0);
}

void	print_test(char *placeholders, ...)
{
	int		i;
	int		num_args;
	va_list	args;

	i = 0;
	num_args = ft_strlen(placeholders);
	va_start(args, placeholders);
	while (i < num_args)
	{
		if (placeholders[i] == 'd')
			printf("%d\n", va_arg(args, int));
		else if (placeholders[i] == 'f')
			printf("%f\n", va_arg(args, double));
		i++;
	}
	va_end(args);
}

int	main(void)
{
	int	a;
	int	b;

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
