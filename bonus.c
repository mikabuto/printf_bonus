#include "ft_printf.h"

int	conversions(char c, t_print *tab, int pos)
{
	if (c == 'c')
		return (ft_print_char(tab, pos));
	if (c == 's')
	 	return (ft_print_str(tab, pos));
	// if (c == 'p')
	// 	return (int_ft_putptr(va_arg(ap, unsigned long)));
	// if (c == 'd' || c == 'i')
	// 	return(int_ft_putnbr(va_arg(ap, int)));
	// if (c == 'u')
	// 	return(int_ft_putunsnbr(va_arg(ap, unsigned int)));
	// if (c == 'X')
	// 	return(int_ft_putneghex((long long int)va_arg(ap, int), 55));
	// if (c == 'x')
	// 	return(int_ft_putneghex((long long int)va_arg(ap, int), 87));
	// if (c == '%')
	// 	return (int_ft_putchar('%'));
	return (0);
}

int	ft_eval_format(t_print *tab, const char *format, int pos)
{
	while (format[pos] && !cspdiuxX(format[pos]))
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
		if (format[pos] >= '0' && format[pos] <= '9')
		{
			while (format[pos] >= '0' && format[pos] <= '9')
			{
				tab->wdt = tab->wdt * 10 + format[pos] - '0';
				++pos;
			}
		}
	}
	// printf("pos = %d\ntab->pnt = %d\n", pos, tab->pnt);
	return (conversions(format[pos], tab, pos));
}

int ft_printf(const char *format, ...)
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

int	main(void)
{
	char	s[] = "%-18.2s\n";
	char	s1[] = "yolololo";
	int a;
	int b;
	ft_printf("012345678901234567890123456789\n");
	printf("% s\n", "nice cock");
	// a = ft_printf(s, s1);
	// b = printf(s, s1);
	// if (a == b)
	// 	printf("return is fine!\n");
	// else
	// 	printf("your func returns %d\noriginal returns %d\n", a, b);
}