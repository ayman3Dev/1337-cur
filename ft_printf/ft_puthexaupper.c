/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:05:28 by aaaraba           #+#    #+#             */
/*   Updated: 2023/12/05 12:31:57 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenhexaupper(size_t n)
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

int	ft_puthexupper(unsigned int n)
{
	char	*hex;
	int		len;

	len = 0;
	if ((size_t)n == 0)
		len = 1;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthexupper(n / 16);
	}
	ft_putchar(hex[n % 16]);
	return (ft_lenhexaupper(n) + len);
}
