/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:28:59 by mikabuto          #+#    #+#             */
/*   Updated: 2022/01/04 16:28:59 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tab(t_print *tab)
{
	clear_tab(tab);
	tab->tl = 0;
}

int	cspdiux(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' \
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	increase_pos(int *a)
{
	*a = 1;
	return (1);
}

int	eval_prc_wdt(int *a, int *b, const char *format, int pos)
{
	*b = 1;
	if (format[pos] > '0' && format[pos] <= '9')
	{
		while (format[pos] >= '0' && format[pos] <= '9')
		{
			*a = (*a) * 10 + format[pos] - '0';
			++pos;
		}
	}
	return (pos);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}
