/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:33:02 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/28 15:17:51 by ycyr-roy         ###   ########.fr       */
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

int	flags_handler(char *str, t_data *data)
{
	size_t	i;

	i = 0;
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

int	width_handler(va_list args, char *str, t_data *data)
{
	size_t	i;

	i = 0;
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
	return (i);
}
// Reads width and precision and then puts it into struct. [FUNCTION CHAIN]
// Part of a function chain until write.
// Returns nb or args

int	prec_handler(va_list args, char *str, t_data *data)
{
	size_t	i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			data->pre = ft_atoi(&str[i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else if (str[i] == '*')
		{
			data->pre = va_arg(args, int);
			i++;
		}
		else if (is_placeholder(str[i]))
			data->pre_itself = 1;
	}
	return (i);
}
