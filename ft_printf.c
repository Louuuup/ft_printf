/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/17 21:12:15 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	placeholder_finder(va_list args, char *str, size_t *len);
int	flag_handler(va_list args, char *str, size_t *len);
int	width_prec_handler(va_list args, char *str, t_format format, size_t *len);
int	types_handler(va_list args, char *str, t_format format, size_t *len);

int	ft_printf(const char *str, ...)
{
	char	*s;
	va_list	args;
	size_t	len;
	int		error;

	s = (char *)str;
	va_start(args, str);
	error = 0;
	len = 0;
	error = placeholder_finder(args, s, &len);
	va_end(args);
	// printf("ft_printf succeded\n");
	return (len);
}

int	placeholder_finder(va_list args, char *str, size_t *len)
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
			{
				flag_handler(args, &str[i], len);
				i++;
			}
		}
		else
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
	// printf("placeholder_finder succeded\n");
	return (i);
}		

// Reads flags and puts it into struct.
//	Part of a function chain until write.
int	flag_handler(va_list args, char *str, size_t *len)
{
	size_t		i;
	t_format	format;

	i = 0;
	while (1)
	{
		if (str[i] == ' ')
			format.flag[0] = str[i++];
		else if (str[i] == '+')
			format.flag[0] = str[i++];
		else if (str[i] == '0')
			format.flag[0] = str[i++];
		else if (str[i] == '-')
			format.flag[0] = str[i++];
		else if (str[i] == '#')
			format.flag[0] = str[i++];
		else
			break ;
	}
	// printf("flag_handler succeded\n");
	return (width_prec_handler(args, &str[i], format, len));
}

// Reads width and precision and then puts it into struct. [FUNCTION CHAIN] 
//	Part of a function chain until write.
int	width_prec_handler(va_list args, char *str, t_format format, size_t *len)
{
	size_t	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		format.width = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		format.precision = ft_atoi(&str[++i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	// printf("width_prec succeded\n");
	return (types_handler(args, &str[i], format, len));
}
// A AJOUTER: UTILISER LES INFOS DANS t_format POUR APPLIQUER FLAGS AVANT DE PRINT.
int	types_handler(va_list args, char *str, t_format format, size_t *len)
{
	size_t	i;

	format.flag[0] = 'a';
	i = 0;
	if (str[i] == 'c')
		return (ft_putchar(va_arg(args, int), len));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(args, char *), len));
	else if (str[i] == 'p')
		return (ft_putptr(va_arg(args, char *), len));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(args, int), len));
	else if (str[i] == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), len));
	// else if (str[i] == 'x')
	// else if (str[i] == 'X')
	// printf("types_handler succeded\n");
	return (0);
}
