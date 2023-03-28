/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:33:07 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/14 15:19:39 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	atoi_nbr(const char *str)
{
	int		n;
	char	*string;

	n = 0;
	string = (char *)str;
	while (*string >= 48 && *string <= 57)
	{
		n *= 10;
		n += (*string - 48);
		string++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int		neg;
	char	*string;

	string = (char *)str;
	neg = 1;
	if (*string == '\0')
		return (0);
	while (*string == 32 || (*string >= 9 && *string <= 13))
	{
		string++;
	}
	if (*string == 43)
		string++;
	else if (*string == 45)
	{
		neg = -neg;
		string++;
	}
	return (atoi_nbr(string) * neg);
}

int	int_len(int n)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return (1 + int_len(-n));
	else if (n > 9)
		return (1 + int_len(n / 10));
	else
		return (1);
}

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	if (s[0] == '\0')
		return (0);
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

// Voids every value in struct.
// TEMP TEST: PRE and WDH at 0 by default instead of -1
void	ft_strct_clean(t_data *data)
{
	data->flag[0] = '\0';
	data->flag[1] = '\0';
	data->flag[2] = '\0';
	data->wdh = 0;
	data->pre = 0;
	data->field_except = 0;
	data->len = 0;
	data->type = '\0';
}
