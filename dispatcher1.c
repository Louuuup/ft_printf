/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:26:06 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/04/12 12:49:57 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	p_dispatcher(unsigned long nb, t_data *data)
{
	int	nb_len;

	nb_len = hex_len(nb) + 2;
	data->flag[3] = '#';
	if (int_disp1(0, nb_len, data))
		return (ERROR);
	if (put_prefix(1, 0, data))
		return (ERROR);
	if (ft_puthex(nb, data->len))
		return (ERROR);
	if (int_disp3(0, nb_len, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts  * [is_lwc = 0 means x. Else X]
// Some are executed before or after "putchar", depending on context.
int	x_dispatcher(unsigned int nb, t_data *data, int is_lwc)
{
	int	nb_len;

	if (data->pre_itself && nb == 0)
		data->pre = nb;
	if (data->flag[3] == '#')
		nb_len = 2;
	else
		nb_len = 0;
	if (!(nb == 0 && data->pre == 0))
		nb_len += hex_len(nb);
	if (int_disp1(0, nb_len, data))
		return (ERROR);
	if (put_prefix(nb, is_lwc, data))
		return (ERROR);
	if (int_disp2(0, nb_len, data))
		return (ERROR);
	return (x_dispatcher1(nb, data, nb_len, is_lwc));
}

int	x_dispatcher1(unsigned int nb, t_data *data, int nb_len, int is_lwc)
{
	if (is_lwc && !(data->pre == 0 && nb == 0))
	{
		if (ft_puthex1(nb, data->len))
			return (ERROR);
	}
	else if (!(data->pre == 0 && nb == 0))
	{
		if (ft_puthex(nb, data->len))
			return (ERROR);
	}
	if (int_disp3(0, nb_len, data))
		return (ERROR);
	return (NO_ERROR);
}

int	s_dispatcher(char *s, t_data *data)
{
	int	s_len;

	if (!s && data->pre_itself == 0)
		return (s_dispatcher("(null)", data));
	else if (s)
		s_len = ft_strlen(s);
	if (data->pre >= 0 && data->pre < s_len)
		s_len = data->pre;
	if (data->pre_itself == 1)
		s_len = 0;
	if (data->flag[2] == '0')
		ft_flood(data->wdh - s_len, data->flag[1], data->len);
	else if (data->flag[1] != '-')
		ft_flood(data->wdh - s_len, ' ', data->len);
	if (!data->pre_itself)
		ft_putstr(s, data->pre, data->len);
	if (data->flag[1] == '-')
		ft_flood(data->wdh - s_len, ' ', data->len);
	return (0);
}
