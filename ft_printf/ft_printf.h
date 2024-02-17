/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:32:20 by aaaraba           #+#    #+#             */
/*   Updated: 2023/12/05 18:50:05 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putdec(int n);
int		ft_puthexalow(unsigned int n);
int		ft_puthexupper(unsigned int n);
int		ft_pradd(void	*n);
int		ft_putudec(unsigned int num);
int		ft_printf(const char *format, ...);

#endif