/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:37:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/23 14:15:56 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Dispatches flags and argmuemnts for all ints.
// Some are executed before or after "putchar", depending on context.
int	int_disp(long long nb, t_format *format, (*f)(long long, int *)int *len)
{
	if (int_dispatcher0(nb, t_format, len))
		return (-1);
}

int	int_dispatcher0(long long nb, t_format *format, int *len)
{
	if (format->flag[0] == '+' && nb >= 0)
		ft_putchar('+', len);
	else if (format->flag[0] == ' ' && nb >= 0)
		ft_putchar(' ', len);
	return (0);
}

// add 0s before when precision is
int	d_dispatcher(va_list args, t_format *format, int *len)
{
	if (format->flag[0] != '\0')
		d_dispatcher1(nb, format, len);
	if (format->flag[1] == '0')
	{
		if (nb < 0)
			ft_putchar('-', len);
		nb *= ft_flood(format->width - int_len(nb), nb, format->flag[1], len);
	}
	else if (format->flag[1] != '-')
		ft_flood(format->width - int_len(nb), nb, ' ', len);
	if (format->precision >= int_len(nb))
	{
		if (nb < 0)
			ft_putstr("-0", -1, len);
		nb *= ft_flood(format->precision - int_len(nb), nb, '0', len);
	}
	ft_putnbr(nb, len);
	if (format->flag[1] == '-')
		ft_flood(format->width - int_len(nb), nb, ' ', len);
	return (0);
}

int	s_dispatcher(va_list args, t_format *format, int *len)
{
	char	*s;

	s = ft_strdup(va_arg(args, char *));
	if (!s)
		return (ft_putstr("(null)", -1, len));
	if (format->flag[1] == '0')
		ft_flood(format->width - ft_strlen(s), 0, format->flag[1], len);
	else if (format->flag[1] != '-')
		ft_flood(format->width - ft_strlen(s), 0, ' ', len);
	ft_putstr(s, format->precision, len);
	if (format->flag[1] == '-')
		ft_flood(format->width - ft_strlen(s), 0, ' ', len);
	free(s);
	return (0);
}

int	p_dispatcher(va_list args, t_format *format, int *len)
{
	int	old_len;

	old_len = *len;
	if (format->flag[1] == '0')
		ft_flood(format->width - 14, 0, format->flag[1], len);
	else if (format->flag[1] != '-')
		ft_flood(format->width - 14, 0, ' ', len);
	ft_putptr(va_arg(args, unsigned long), len);
	if (format->flag[1] == '-')
		ft_flood(format->width - (*len - old_len), 0, ' ', len);
	return (0);
}
