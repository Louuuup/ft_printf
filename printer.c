/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:16:06 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/17 21:07:36 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, size_t *len)
{
	write(1, &c, 1);
	len++;
	return (0);
}

int	ft_putstr(char *s, size_t *len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
	return (0);
}

int	ft_putnbr(int n, size_t *len)
{
	if (n == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		ft_putnbr(147483648, len);
	}
	else if (n == 0)
		ft_putchar('0', len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
		ft_putnbr(n, len);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + 48, len);
	return (0);
}

int	ft_putnbr_unsigned(unsigned int n, size_t *len)
{
	if (n == 0)
		ft_putchar('0', len);
	else if (n < 0)
	{
		return (1);
	}
	else if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, len);
		ft_putnbr_unsigned(n % 10, len);
	}
	else
		ft_putchar(n + 48, len);
	return (0);
}

int	ft_puthexa(int n, size_t *len)
{
	if (n <= 9)
		ft_putchar(n + 48, len);
	return (0);
}
