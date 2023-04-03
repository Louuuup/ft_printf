/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:16:06 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/04/02 14:45:48 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *len)
{
	*len += 1;
	if (write(1, &c, 1) < 0)
		return (-1);
	return (0);
}

// Print the string for "max" characters,
// or everything if max = -1
int	ft_putstr(char *s, int max, int *len)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", -1, len));
	while (s[i] && (i < max || max == -1))
	{
		ft_putchar(s[i], len);
		i++;
	}
	return (0);
}

int	ft_putnbr(int n, int *len)
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

int	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n == 0)
		ft_putchar('0', len);
	else if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, len);
		ft_putnbr_unsigned(n % 10, len);
	}
	else
		ft_putchar(n + 48, len);
	return (0);
}
