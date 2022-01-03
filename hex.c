#include "ft_printf.h"

void	print_hex(t_print *tab, char *hex, int shift)
{
	int	strlen;
	int	i;

	strlen = ft_strlen(hex) + 2 * tab->hash;
	if (tab->prc)
		ft_fill(tab, ft_min(strlen, tab->prc), '0');
	if (tab->wdt && !(tab->dash) && !(tab->zero))
		ft_fill(tab, ft_min(strlen, tab->wdt), ' ');
	if (tab->wdt && !(tab->dash) && tab->zero)
		ft_fill(tab, ft_min(strlen, tab->wdt), '0');
	if (hex[0] != '0' && tab->hash && shift == 87)
		tab->tl += write(1, "0x", 2);
	if (hex[0] != '0' && tab->hash && shift == 55)
		tab->tl += write(1, "0X", 2);
	i = -1;
	while (hex[++i])
		tab->tl += write(1, &(hex[i]), 1);
	if (tab->wdt && tab->dash)
		ft_fill(tab, ft_min(strlen, tab->wdt), ' ');
	clear_tab(tab);
	free(hex);
}

char	*ft_putposhex(unsigned long long int num, int shift)
{
	char						*hex;
	unsigned long long int		rem;
	int							j;
	int							i;

	j = 0;
	i = -1;
	hex = (char *)malloc(17);
	if (!num)
		hex[j++] = '0';
	while (num)
	{
		rem = num % 16;
		if (rem < 10)
			hex[j++] = 48 + rem;
		else
			hex[j++] = shift + rem;
		num /= 16;
	}
	while (++i <= (j - 1) / 2)
		ft_swap(&(hex[i]), &(hex[(j - 1) - i]));
	hex[j] = '\0';
	return (hex);
}

int	ft_putneghex(t_print *tab, int shift)
{
	long long int	num;

	num = (long long int)va_arg(tab->args, int);
	if (num < 0)
		num = 4294967296 + num;
	print_hex(tab, ft_putposhex(num, shift), shift);
	return (1);
}