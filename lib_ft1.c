/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:45:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/22 13:24:44 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

// Floods console with 'c' and will do it "size" times.
// "nb" is for int. Else, nb should be 0.
// Returns 1 if int is pos. or -1 if int is neg.
int	ft_flood(int size, char c, int *len)
{
	while (size > 0)
	{
		if (ft_putchar(c, len))
			return (ERROR);
		size--;
	}
	return (NO_ERROR);
}

int	hex_len(unsigned long n)
{
	int	i;

	i = 1;
	if (n / 16)
		i += hex_len(n / 16);
	return (i);
}

int	put_prefix(int nb, int is_lwc, t_data *data)
{
	if (data->flag[3] == '#' && nb != 0)
	{
		if (is_lwc)
		{
			if (ft_putstr("0X", -1, data->len))
				return (ERROR);
		}
		else
		{
			if (ft_putstr("0x", -1, data->len))
				return (ERROR);
		}
	}
	return (NO_ERROR);
}
