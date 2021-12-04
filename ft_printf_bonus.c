/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:24:03 by mikabuto          #+#    #+#             */
/*   Updated: 2021/12/04 18:01:36 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	not_conversion(char c)
{
	return (c != 'c' && c != 's' && c != 'p' && c != 'd' && \
	c != 'i' && c != 'u' && c != '%' && c != 'X' && c != 'x');
}

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->tl = 0;
	tab->plus = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->sp = 0;
	tab->hash = 0;
	return (tab);
}

int	ft_eval_format(t_print *tab, const char *format, int i)
{
	while (not_conversion(format[++i]))
	{
		if (format[i] == '.')
			tab->pnt = 1;
		if (format[i] == '-')
			tab->dash = 1;
		if (format[i] == '0')
			tab->zero = 1;
		if (format[i] == ' ')
			tab->sp = 1;
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			i = ft_eval_format(tab, format, i);
		else
			len += write(1, &format[i], 1);
	}
	va_end(tab->args);
	len += tab->tl;
	free(tab);
	return (len);
}
