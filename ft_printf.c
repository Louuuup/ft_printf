/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/28 15:09:54 by ycyr-roy         ###   ########.fr       */
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
	len = 0;
	data.len = &len;
	error = arguments_finder(args, s, &data);
	va_end(args);
	if (error < 0)
		return (ERROR);
	return (len);
}

int	arguments_finder(va_list args, char *str, t_data *data)
{
	size_t	i;
	int		err_check;

	i = 0;
	err_check = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_strct_clean(data);
			err_check = arguments_handler(args, &str[i], data);
			if (err_check < 0)
				return (ERROR);
			i += err_check + 1;
		}
		else
		{
			if (ft_putchar(str[i], data->len))
				return (ERROR);
			i++;
		}
	}
	return (NO_ERROR);
}

// Reads flags and puts it into struct.
//	Part of a function chain until write.
// Returns the amount of flags + arguments
int	arguments_handler(va_list args, char *str, t_data *data)
{
	size_t	i;

	i = 0;
	i += flags_handler(str, data);
	i += width_handler(args, &str[i], data);
	i += prec_handler(args, &str[i], data);
	if (main_dispatcher(args, &str[i], data))
		return (ERROR);
	return (i);
}
