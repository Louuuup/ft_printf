/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/27 21:47:09 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arguments_finder(va_list args, char *str, t_data *data);
int	arguments_handler(va_list args, char *str, t_data *data);

int	ft_printf(const char *str, ...)
{
	char	*s;
	int		len;
	int		error;
	va_list	args;
	t_data	data;

	s = (char *)str;
	va_start(args, str);
	ft_strct_clean(&data);
	len = 0;
	data.len = &len;
	error = arguments_finder(args, s, &data);
	va_end(args);
	if (error)
		return (ERROR);
	return (len);
}

int	arguments_finder(va_list args, char *str, t_data *data)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i += 1 + arguments_handler(args, &str[i], data);
		}
		else
		{
			if (ft_putchar(str[i], data->len))
				return (ERROR);
			i++;
		}
	}
	return (i);
}

// Reads flags and puts it into struct.
//	Part of a function chain until write.
// Returns the amount of flags + arguments
int	arguments_handler(va_list args, char *str, t_data *data)
{
	size_t	i;

	i = 0;
	i += flags_handler(str, data, i);
	i += width_handler(args, str, data, i);
	i += prec_handler(args, str, data, i);
	if (types_handler(args, &str[i], data))
		return (ERROR);
	return (i);
}
