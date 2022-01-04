/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:18:22 by mikabuto          #+#    #+#             */
/*   Updated: 2022/01/04 18:18:22 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	clear_tab(t_print *tab)
{
	tab->wdt = 0;		//width field
	tab->prc = 0;		//precision
	tab->zero = 0;		// flag '0'
	tab->pnt = 0;		// .
	tab->dash = 0;		// -
	tab->sign = 0;		//pos or neg numer
	tab->perc = 0;		// %
	tab->sp = 0;		// ' '
	tab->hash = 0;		// #
	tab->plus = 0;		// +
	tab->is_zero = 0;
}

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_putchar(char c, t_print *tab)
{
	tab->tl += write(1, &c, 1);
}

int	ft_putstr(char *str, t_print *tab)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		tab->tl += write(1, &(str[i]), 1);
	}
	return (1);
}
