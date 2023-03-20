/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:12:56 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/20 17:50:58 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned int s, int *len)
{
	ft_putstr("0x", len);
	ft_puthexa(s, len);
	return (0);
}

int	ft_puthexa(unsigned int n, int *len)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48, len);
	else if (n >= 10 && n <= 15)
		ft_putchar(n + 87, len);
	else
	{
		ft_puthexa(n / 16, len);
		ft_puthexa(n % 16, len);
	}
	return (0);
}

int	ft_puthexa_alt(unsigned int n, int *len)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48, len);
	else if (n >= 10 && n <= 15)
		ft_putchar(n + 65, len);
	else
	{
		ft_puthexa_alt(n / 16, len);
		ft_puthexa_alt(n % 16, len);
	}
	return (0);
}
