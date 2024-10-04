/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agragera <agragera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:30:40 by agragera          #+#    #+#             */
/*   Updated: 2024/03/25 00:30:40 by agragera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_putnbr_hex(unsigned long n, char *base);
void	ft_putnbr_u(unsigned int n, int fd);
void	ft_putptr_fd(void *ptr, int fd);
void	handle_specifier( char c, va_list ap);
int		ft_printf(const char *format, ...);

#endif
