/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:33:02 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/27 21:32:58 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_placeholder(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	else if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	flags_handler(char *str, t_data *data, size_t i)
{
	while (1)
	{
		if (str[i] == ' ')
			data->flag[0] = str[i++];
		else if (str[i] == '+')
			data->flag[0] = str[i++];
		else if (str[i] == '0')
			data->flag[1] = str[i++];
		else if (str[i] == '-')
			data->flag[1] = str[i++];
		else if (str[i] == '#')
			data->flag[2] = str[i++];
		else
			break ;
	}
	return (i);
}

int	width_handler(va_list args, char *str, t_data *data, size_t i)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		data->wdh = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else if (str[i] == '*')
	{
		data->wdh = va_arg(args, int);
		i++;
	}
	else if (is_placeholder(str[i]))
		i++;
	return (i);
}
// Reads width and precision and then puts it into struct. [FUNCTION CHAIN]
// Part of a function chain until write.
// Returns nb or args

int	prec_handler(va_list args, char *str, t_data *data, size_t i)
{
	if (str[i] == '.')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			data->pre = ft_atoi(&str[++i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		i++;
	}
	return (i);
}

int	types_handler(va_list args, char *str, t_data *data)
{
	size_t	i;

	i = 0;
	if (str[i] == 'c')
		return (c_dispatcher(va_arg(args, int), data));
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
