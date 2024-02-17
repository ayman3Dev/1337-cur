/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:32:10 by aaaraba           #+#    #+#             */
/*   Updated: 2023/12/05 12:32:25 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenudec(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_putudec(unsigned int num)
{
	if (num > 9)
	{
		ft_putudec(num / 10);
	}
	ft_putchar((num % 10) + 48);
	return (ft_lenudec(num));
}
