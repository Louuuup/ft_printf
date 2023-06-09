/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:46:50 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/04/12 12:47:01 by ycyr-roy         ###   ########.fr       */
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
// MOVED '0' handler to disp2 to deal with negatives before.
int	int_disp1(int neg, int nb_len, t_data *data)
{
	if (data->flag[2] == '0' && data->wdh > data->pre && data->pre > 0)
		data->flag[2] = '\0';
	if (data->flag[1] != '-' && data->flag[2] != '0' && data->wdh > data->pre)
	{
		if (data->wdh && data->pre && data->wdh > data->pre)
		{
			if (data->pre >= nb_len)
				return (ft_flood(data->wdh - data->pre - neg, ' ', data->len));
			else
				return (ft_flood(data->wdh - nb_len, ' ', data->len));
		}
		else
			return (ft_flood(data->wdh - nb_len, ' ', data->len));
	}
	return (NO_ERROR);
}

// Handles Precisions (PRE)
// + '0' handlers from disp1
int	int_disp2(int neg, int nb_len, t_data *data)
{
	if (data->flag[2] == '0' && data->wdh > data->pre)
		return (ft_flood(data->wdh - nb_len, '0', data->len));
	if (data->pre > 0)
		return (ft_flood(data->pre - nb_len + neg, '0', data->len));
	return (NO_ERROR);
}

// Handles '-' and "post-word" width arguments
int	int_disp3(int neg, int nb_len, t_data *data)
{
	if (data->flag[1] == '-' && data->wdh > data->pre)
	{
		if (data->pre > 0 && data->pre > nb_len)
			return (ft_flood(data->wdh - data->pre - neg, ' ', data->len));
		else
			return (ft_flood(data->wdh - nb_len, ' ', data->len));
	}
	return (NO_ERROR);
}
