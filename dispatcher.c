/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:37:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/23 23:24:29 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// POSSIBLE TO STACK IF STATEMENTS IF NEEDED (||)
// Dispatches flags and argmuemnts for all ints.
// Some are executed before or after "putchar", depending on context.
int	int_disp(long long nb, t_format *fmt, int (*f)(long long, int *), int *len)
{
	if (int_disp0(nb, fmt, len))
		return (ERROR);
	if (int_disp1(nb, fmt, len))
		return (ERROR);
	if (int_disp1(nb, fmt, len))
		return (ERROR);
	if (int_disp2(nb, fmt, len))
		return (ERROR);
	if (f(nb, len))
		return (ERROR);
	if (int_disp3(nb, fmt, len))
		return (ERROR);
	return (NO_ERROR);
}

// Handles '+' and ' ' arguments.(FLG[0])
int	int_disp0(long long nb, t_format *format, int *len)
{
	if (fmt->flag[0] == '+' && nb >= 0)
		return (ft_putchar('+', len));
	else if (fmt->flag[0] == ' ' && nb >= 0)
		return (ft_putchar(' ', len));
	return (NO_ERROR);
}

// Handles '0' and width arguments.(FLG[1] + WDH)
// "fmt" instead of "format" here, because of less space
// If PRE is bigger than WDH, no WDH.
int	int_disp1(long long nb, t_format *fmt, int *len)
{
	if (fmt->flags[1] != '-' && fmt->flags[1] != '0' && fmt->wdh > fmt->pre)
		return (ft_flood(fmt->wdh - int_len(nb) - fmt->pre, nb, ' ', len));
	if (fmt->flag[1] == '0' && fmt->wdh > fmt->pre)
	{
		if (nb < 0)
		{
			if (ft_putchar('-', len))
				return (ERROR);
			nb = -nb;
		}
		return (ft_flood(fmt->wdh - int_len(nb) - fmt->pre, fmt->flag[1], len));
	}
	return (NO_ERROR);
}

// Handles Precisions (PRE)
int	int_disp2(long long nb, t_format *format, int *len)
{
	if (fmt->wdh < fmt->pre)
		return (ft_flood(fmt->pre - int_len(nb) - fmt->wdh));
	return (NO_ERROR);
}

// Handles '-' and "post-word" width arguments
// (FLG[1] + WDH)
int	int_disp3(long long nb, t_format *format, int *len)
{
	if (fmt->flag[1] == '-')
		return (ft_flood(fmt->wdh - int_len(nb), nb, ' ', len));
	return (NO_ERROR)
}
int	d_dispatcher(va_list args, t_format *format, int *len)
{
	if (fmt->flag[1] == '0')
	{
		if (nb < 0)
			ft_putchar('-', len);
		nb *= ft_flood(fmt->wdh - int_len(nb), nb, fmt->flag[1], len);
	}
	else if (fmt->flag[1] != '-')
		ft_flood(fmt->wdh - int_len(nb), nb, ' ', len);
	if (fmt->precision >= int_len(nb))
	{
		if (nb < 0)
			ft_putstr("-0", -1, len);
		nb *= ft_flood(fmt->precision - int_len(nb), nb, '0', len);
	}
	ft_putnbr(nb, len);
	if (fmt->flag[1] == '-')
		ft_flood(fmt->wdh - int_len(nb), nb, ' ', len);
	return (0);
}

int	s_dispatcher(va_list args, t_format *format, int *len)
{
	char	*s;

	s = ft_strdup(va_arg(args, char *));
	if (!s)
		return (ft_putstr("(null)", -1, len));
	if (fmt->flag[1] == '0')
		ft_flood(fmt->wdh - ft_strlen(s), 0, fmt->flag[1], len);
	else if (fmt->flag[1] != '-')
		ft_flood(fmt->wdh - ft_strlen(s), 0, ' ', len);
	ft_putstr(s, fmt->precision, len);
	if (fmt->flag[1] == '-')
		ft_flood(fmt->wdh - ft_strlen(s), 0, ' ', len);
	free(s);
	return (0);
}

int	p_dispatcher(va_list args, t_format *format, int *len)
{
	int	old_len;

	old_len = *len;
	if (fmt->flag[1] == '0')
		ft_flood(fmt->wdh - 14, 0, fmt->flag[1], len);
	else if (fmt->flag[1] != '-')
		ft_flood(fmt->width - 14, 0, ' ', len);
	ft_putptr(, len);
	if (fmt->flag[1] == '-')
		ft_flood(fmt->width - (*len - old_len), 0, ' ', len);
	return (0);
}
