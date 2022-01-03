#include "ft_printf.h"

int	ft_num_len(long long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_power(int a)
{
	int	n;

	n = 1;
	while (a--)
		n *= 10;
	return (n);
}