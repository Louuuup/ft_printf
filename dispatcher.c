/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:37:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/27 15:30:34 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main_dispatcher(va_list args, char *str, t_data *data, int *len)
{
	size_t	i;

	i = 0;
	if (str[i] == 'c')
		return (c_dispatcher(va_arg(args, int), data, len));
	else if (str[i] == 's')
		return (s_dispatcher(va_arg(args, char *), data, len));
	else if (str[i] == 'p')
		return (p_dispatcher(va_arg(args, unsigned long), data, len));
	else if (str[i] == 'd' || str[i] == 'i')
		return (d_dispatcher(va_arg(args, int), data, len));
	else if (str[i] == 'u')
		return (u_dispatcher(va_arg(args, unsigned int), data, len));
	else if (str[i] == 'x')
		return (x_dispatcher(va_arg(args, unsigned int), data, 0, len));
	else if (str[i] == 'X')
		return (x_dispatcher(va_arg(args, unsigned int), data, 1, len));
	else if (str[i] == '%')
		return (c_dispatcher('%', data, len));
	return (NO_ERROR);
}

// Handles '+' and ' ' arguments.(FLG[0])
int	int_disp0(long long nb, t_data *data, int *len)
{
	if (data->flag[0] == '+' && nb >= 0)
		return (ft_putchar('+', len));
	else if (data->flag[0] == ' ' && nb >= 0)
		return (ft_putchar(' ', len));
	return (NO_ERROR);
}

// Handles '0' and width arguments.(FLG[1] + WDH)
// "fmt" instead of "data" here, because of less space
// If PRE is bigger than WDH, no WDH.
int	int_disp1(int nb_len, t_data *fmt, int *len)
{
	if (fmt->flag[1] != '-' && fmt->flag[1] != '0' && fmt->wdh > fmt->pre)
		return (ft_flood(fmt->wdh - nb_len - fmt->pre, ' ', len));
	if (fmt->flag[1] == '0' && fmt->wdh > fmt->pre)
		return (ft_flood(fmt->wdh - nb_len - fmt->pre, fmt->flag[1], len));
	return (NO_ERROR);
}

// Handles Precisions (PRE)
int	int_disp2(long long nb, t_data *data, int *len)
{
	if (data->wdh < data->pre)
		return (ft_flood(data->pre - int_len(nb) - data->wdh, '0', len));
	return (NO_ERROR);
}

// Handles '-' and "post-word" width arguments
// (FLG[1] + WDH)
int	int_disp3(long long nb, t_data *data, int *len)
{
	if (data->flag[1] == '-')
		return (ft_flood(data->wdh - int_len(nb), ' ', len));
	return (NO_ERROR);
}

// int	d_dispatcher(va_list args, t_data *data, int *len)
// {
// 	if (fmt->flag[1] == '0')
// 	{
// 		if (nb < 0)
// 			ft_putchar('-', len);
// 		nb *= ft_flood(fmt->wdh - int_len(nb), nb, fmt->flag[1], len);
// 	}
// 	else if (fmt->flag[1] != '-')
// 		ft_flood(fmt->wdh - int_len(nb), nb, ' ', len);
// 	if (fmt->precision >= int_len(nb))
// 	{
// 		if (nb < 0)
// 			ft_putstr("-0", -1, len);
// 		nb *= ft_flood(fmt->precision - int_len(nb), nb, '0', len);
// 	}
// 	ft_putnbr(nb, len);
// 	if (fmt->flag[1] == '-')
// 		ft_flood(fmt->wdh - int_len(nb), nb, ' ', len);
// 	return (0);
// }

// int	p_dispatcher(va_list args, t_data *data, int *len)
// {
// 	int	old_len;

// 	old_len = *len;
// 	if (fmt->flag[1] == '0')
// 		ft_flood(fmt->wdh - 14, 0, fmt->flag[1], len);
// 	else if (fmt->flag[1] != '-')
// 		ft_flood(fmt->width - 14, 0, ' ', len);
// 	ft_putptr(, len);
// 	if (fmt->flag[1] == '-')
// 		ft_flood(fmt->width - (*len - old_len), 0, ' ', len);
// 	return (0);
// }
