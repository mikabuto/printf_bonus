/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:16 by mikabuto          #+#    #+#             */
/*   Updated: 2022/01/04 14:30:16 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversions(char c, t_print *tab, int pos)
{
	if (c == 'c')
		return (ft_print_char(tab) + pos);
	if (c == 's')
		return (ft_print_str(tab) + pos);
	if (c == 'p')
		return (ft_putptr(tab) + pos);
	if (c == 'd' || c == 'i')
		return (ft_putnbr(tab) + pos);
	if (c == 'u')
		return (ft_putunsnbr(tab) + pos);
	if (c == 'X')
		return (ft_putneghex(tab, 55) + pos);
	if (c == 'x')
		return (ft_putneghex(tab, 87) + pos);
	if (c == '%')
	{
		tab->perc = 1;
		return (ft_print_perc(tab) + pos);
	}
	return (0);
}

int	ft_eval_format(t_print *tab, const char *format, int pos)
{
	while (format[pos] && !cspdiux(format[pos]))
	{
		if (format[pos] == '.')
			pos = eval_prc_wdt(&(tab->prc), &(tab->pnt), format, pos + 1);
		if (format[pos] == '0')
			pos = eval_prc_wdt(&(tab->wdt), &(tab->zero), format, pos + 1);
		if (format[pos] == '-')
			pos = eval_prc_wdt(&(tab->wdt), &(tab->dash), format, pos + 1);
		if (format[pos] == '#')
			pos += increase_pos(&(tab->hash));
		if (format[pos] == ' ')
			pos += increase_pos(&(tab->sp));
		if (format[pos] == '+')
			pos += increase_pos(&(tab->plus));
		if (format[pos] > '0' && format[pos] <= '9')
		{
			while (format[pos] >= '0' && format[pos] <= '9')
			{
				tab->wdt = tab->wdt * 10 + format[pos] - '0';
				++pos;
			}
		}
	}
	return (conversions(format[pos], tab, pos));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	init_tab(tab);
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i++], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free(tab);
	return (ret);
}

// int	main(void)
// {
// 	char	s[] = "%02.0d|\n";
// 	//char	s1[] = "";
// 	int dec = 0;
// 	int a;
// 	int b;
// 	ft_printf("012345678901234567890123456789\n");
// 	a = printf(s, dec);
// 	b = ft_printf(s, dec);
// 	if (a == b)
// 		printf("return is fine!\n");
// 	else
// 		printf("original returns %d\nyour func returns %d\n", a, b);
// }
