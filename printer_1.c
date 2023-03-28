/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:12:56 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/24 11:35:07 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Adds "0x" and prints th rest in Hexa form
int	ft_putptr(unsigned long s, int *len)
{
	ft_putstr("0x", -1, len);
	ft_puthex(s, len);
	return (0);
}

// Standard form of Hexadecimal, in lowercase
int	ft_puthex(unsigned long n, int *len)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48, len);
	else if (n >= 10 && n <= 15)
		ft_putchar(n + 87, len);
	else
	{
		ft_puthex(n / 16, len);
		ft_puthex(n % 16, len);
	}
	return (0);
}

// Alternative form of Hexadecimal, with capital letters
int	ft_puthex1(unsigned long n, int *len)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48, len);
	else if (n >= 10 && n <= 15)
		ft_putchar(n + 55, len);
	else
	{
		ft_puthex1(n / 16, len);
		ft_puthex1(n % 16, len);
	}
	return (0);
}
