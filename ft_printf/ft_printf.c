/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:32:04 by aaaraba           #+#    #+#             */
/*   Updated: 2023/12/06 15:34:06 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handletype(const char *format, va_list s, int count)
{
	if (*format == 'c')
		count += ft_putchar(va_arg(s, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(s, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putdec(va_arg(s, int));
	else if (*format == 'p')
		count += ft_pradd(va_arg(s, void *));
	else if (*format == 'u')
		count += ft_putudec(va_arg(s, unsigned int));
	else if (*format == 'x')
		count += ft_puthexalow(va_arg(s, unsigned int));
	else if (*format == 'X')
		count += ft_puthexupper(va_arg(s, unsigned int));
	else if (*format == '%')
	{
		write (1, "%", 1);
		count++;
	}
	else
	{
		write (1, format, 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		s;
	int			count;

	count = 0;
	if (write (1, "", 0) == -1)
		return (-1);
	va_start(s, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = ft_handletype (format, s, count);
		}
		else
		{
			write (1, format, 1);
			count++;
		}
		format++;
	}
	va_end(s);
	return (count);
}
