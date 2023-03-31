/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:37:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/30 22:08:25 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main_dispatcher(va_list args, char *str, t_data *data)
{
	size_t	i;

	i = 0;
	if (str[i] == 'c')
		return (c_dispatcher(va_arg(args, int), data));
	else if (str[i] == 's')
		return (s_dispatcher(va_arg(args, char *), data));
	else if (str[i] == 'p')
		return (p_dispatcher(va_arg(args, unsigned long), data));
	else if (str[i] == 'd' || str[i] == 'i')
		return (d_dispatcher(va_arg(args, int), data));
	else if (str[i] == 'u')
		return (u_dispatcher(va_arg(args, unsigned int), data));
	else if (str[i] == 'x')
		return (x_dispatcher(va_arg(args, unsigned int), data, 0));
	else if (str[i] == 'X')
		return (x_dispatcher(va_arg(args, unsigned int), data, 1));
	else if (str[i] == '%')
		return (c_dispatcher('%', data));
	return (NO_ERROR);
}

// Handles '+' and ' ' arguments.(FLG[0])
int	int_disp0(long long nb, t_data *data)
{
	if (data->flag[0] == '+' && nb >= 0)
		return (ft_putchar('+', data->len));
	else if (data->flag[0] == ' ' && nb >= 0)
		return (ft_putchar(' ', data->len));
	return (NO_ERROR);
}

// Handles '0' and width arguments.(FLG[1] + WDH)
// "data" instead of "data" here, because of less space
// If PRE is bigger than WDH, no WDH.
// If WDH is bigger than existing PRE, it is WDH -= PRE
// EXCEPTION: If flag is '0' + conditions before, flag '0' is removed.
int	int_disp1(int nb, int nb_len, t_data *data)
{
	if (data->flag[1] != '-' && data->flag[1] != '0' && data->wdh > data->pre)
	{
		if (data->wdh && data->pre && data->wdh > data->pre)
			return (ft_flood(data->wdh - data->pre, ' ', data->len));
		else
			return (ft_flood(data->wdh - nb_len - data->pre, ' ', data->len));
	}
	if (data->flag[1] == '0' && data->wdh > data->pre)
	{
		if (data->wdh && data->pre && data->wdh > data->pre)
		{
			if (nb < 0)
				return (ft_flood(data->wdh - data->pre - 1, ' ', data->len));
			return (ft_flood(data->wdh - data->pre, ' ', data->len));
		}
		else
			return (ft_flood(data->wdh - nb_len - data->pre, data->flag[1],
					data->len));
	}
	return (NO_ERROR);
}

// Handles Precisions (PRE)
int	int_disp2(int nb, int nb_len, t_data *data)
{
	if (data->pre)
		return (ft_flood(data->pre - nb_len, '0', data->len));
	// else if (data->pre && data->wdh > data->pre)
	nb += 0;
	return (NO_ERROR);
}

// Handles '-' and "post-word" width arguments
int	int_disp3(int nb_len, t_data *data)
{
	if (data->flag[1] == '-')
	{
		if (data->wdh && data->pre && data->wdh > data->pre)
			return (ft_flood(data->wdh - data->pre, ' ', data->len));
		else
			return (ft_flood(data->wdh - nb_len - data->pre, ' ', data->len));
	}
	return (NO_ERROR);
}

// int	d_dispatcher(va_list args, t_data *data, int *len)
// {
// 	if (data->flag[1] == '0')
// 	{
// 		if (nb < 0)
// 			ft_putchar('-');
// 		nb *= ft_flood(data->wdh - int_len(nb), nb, data->flag[1]);
// 	}
// 	else if (data->flag[1] != '-')
// 		ft_flood(data->wdh - int_len(nb), nb, ' ');
// 	if (data->precision >= int_len(nb))
// 	{
// 		if (nb < 0)
// 			ft_putstr("-0", -1);
// 		nb *= ft_flood(data->precision - int_len(nb), nb, '0');
// 	}
// 	ft_putnbr(nb);
// 	if (data->flag[1] == '-')
// 		ft_flood(data->wdh - int_len(nb), nb, ' ');
// 	return (0);
// }

// int	p_dispatcher(va_list args, t_data *data, int *len)
// {
// 	int	old_len;

// 	old_len = *len;
// 	if (data->flag[1] == '0')
// 		ft_flood(data->wdh - 14, 0, data->flag[1]);
// 	else if (data->flag[1] != '-')
// 		ft_flood(data->width - 14, 0, ' ');
// 	ft_putptr();
// 	if (data->flag[1] == '-')
// 		ft_flood(data->width - (*len - old_len), 0, ' ');
// 	return (0);
// }
