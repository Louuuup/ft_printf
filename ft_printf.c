/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/23 23:27:51 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	placeholder_finder(va_list args, char *str, int *len);
int	flag_handler(va_list args, char *str, int *len);
int	width_prec_handler(va_list args, char *str, t_format *format, int *len);
int	types_handler(va_list args, char *str, t_format *format, int *len);

int	ft_printf(const char *str, ...)
{
	char	*s;
	va_list	args;
	int		len;
	int		error;

	s = (char *)str;
	va_start(args, str);
	error = 0;
	len = 0;
	error = placeholder_finder(args, s, &len);
	va_end(args);
	return (len);
}

int	placeholder_finder(va_list args, char *str, int *len)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_putchar(str[i++], len);
			else
				i += 1 + flag_handler(args, &str[i], len);
		}
		else
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
	return (i);
}

// Reads flags and puts it into struct.
//	Part of a function chain until write.
// Returns the amount of flags + arguments
int	flag_handler(va_list args, char *str, int *len)
{
	size_t		i;
	t_format	format;

	i = 0;
	ft_strct_clean(&format);
	while (1)
	{
		if (str[i] == ' ')
			format.flag[0] = str[i++];
		else if (str[i] == '+')
			format.flag[0] = str[i++];
		else if (str[i] == '0')
			format.flag[1] = str[i++];
		else if (str[i] == '-')
			format.flag[1] = str[i++];
		else if (str[i] == '#')
			format.flag[2] = str[i++];
		else
			break ;
	}
	return (i + width_prec_handler(args, &str[i], &format, len));
}

// Reads width and precision and then puts it into struct. [FUNCTION CHAIN]
//	Part of a function chain until write.
// Returns nb or args
int	width_prec_handler(va_list args, char *str, t_format *format, int *len)
{
	size_t	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		format->width = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		format->precision = ft_atoi(&str[++i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i + types_handler(args, &str[i], format, len));
}

int	types_handler(va_list args, char *str, t_format *format, int *len)
{
	size_t	i;

	// format->flag[0] = 'a'; ?????
	i = 0;
	if (str[i] == 'c')
		return (int_disp(va_arg(args, int), format, ft_putchar, len));
	else if (str[i] == 's')
		return (s_dispatcher(args, format, len));
	else if (str[i] == 'p')
		return (int_disp(va_arg(args, unsigned long), format, ft_putptr, len));
	else if (str[i] == 'd' || str[i] == 'i')
		return (int_disp(va_arg(args, int), format, ft_putnbr, len));
	else if (str[i] == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), len));
	else if (str[i] == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), len));
	else if (str[i] == 'X')
		return (ft_puthexa_alt(va_arg(args, unsigned int), len));
	else if (str[i] == '%')
		return (ft_(va_arg(args, unsigned int), len));
	return (0);
}
