/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pradd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:48:45 by aaaraba           #+#    #+#             */
/*   Updated: 2023/12/05 18:48:46 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenadd(size_t n)
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

void	ft_pupo(size_t n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_pupo(n / 16);
	}
	ft_putchar(hex[n % 16]);
}

int	ft_pradd(void	*n)
{
	int	len;

	len = 0;
	if ((size_t)n == 0)
		len = 1;
	ft_putstr("0x");
	ft_pupo((size_t)n);
	return (ft_lenadd((size_t)n) + 2 + len);
}
