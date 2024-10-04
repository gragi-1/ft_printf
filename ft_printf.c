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
#include <stdarg.h>
#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long n, char *base)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}

void	ft_putnbr_u(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_u(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	address;
	char				*hex_digits;
	char				buffer[17];
	int					i;

	address = (unsigned long long)ptr;
	hex_digits = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex_digits[address % 16];
		address /= 16;
		i--;
	}
	buffer[16] = '\0';
	ft_putstr_fd(buffer, fd);
}

void	handle_specifier( char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		ft_putptr_fd(va_arg(ap, void *), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int), 1);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count_chars;
	int		i;

	count_chars = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			handle_specifier(format[++i], ap);
		else
			ft_putchar_fd(format[i], 1);
		count_chars++;
		i++;
	}
	va_end(ap);
	return (count_chars);
}
