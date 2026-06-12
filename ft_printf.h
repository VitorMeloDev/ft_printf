/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:15:23 by vfreitass         #+#    #+#             */
/*   Updated: 2026/06/12 00:15:23 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		check_input(const char *str, va_list *lst);

int		vm_print_string(va_list *lst);
int		vm_print_int(va_list *lst);
int		vm_print_uint(va_list *lst);
int		vm_print_hex(unsigned int x, int format);
int		vm_print_ptr(va_list *lst);

char	*ft_uitoa(unsigned int n);

#endif