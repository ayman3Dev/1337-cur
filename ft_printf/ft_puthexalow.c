/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexalow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:52:57 by aaaraba           #+#    #+#             */
/*   Updated: 2023/12/05 12:31:37 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenhexalow(size_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_puthexalow(unsigned int n)
{
	char	*hex;
	int		len;

	len = 0;
	if ((size_t)n == 0)
		len = 1;
	hex = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthexalow(n / 16);
	}
	ft_putchar(hex[n % 16]);
	return (ft_lenhexalow(n) + len);
}
