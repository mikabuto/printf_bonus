#include "ft_printf.h"

void	init_tab(t_print *tab)
{
	tab->wdt = 0;		//width field
	tab->prc = 0;		//precision
	tab->zero = 0;		// flag '0'
	tab->pnt = 0;		// .
	tab->dash = 0;		// -
	tab->tl = 0;		//total length
	tab->sign = 0;		//pos or neg numer
	tab->is_zero = 0;	//is number zero?
	tab->perc = 0;		// %
	tab->sp = 0;		// ' '
	tab->hash = 0;		// #
	tab->plus = 0;		// +
}

int	cspdiuxX(char c)
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
	while (format[pos] >= '0' && format[pos] <= '9')
	{
		*a = (*a) * 10 + format[pos] - '0';
		++pos;
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