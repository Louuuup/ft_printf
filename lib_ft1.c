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

/// TO DO: struct of struct? Each '%' needs somehow its own struct.
// /!\ Probly not needed

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*cp;

	cp = (unsigned char *)s;
	while (n--)
	{
		*cp++ = 0;
	}
	return (s);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
