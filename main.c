#include <stdio.h>

int	main(void)
{
	printf("Columns:\n012345678901234567890\n");
	printf("%8%| %%8%%\n");
	printf("%x| %%x[512345]\n", 512345);
	printf("%#x| %%#x[512345]\n", 512345);
	printf("%8.18d| %%8.18d[512345]\n", 512345);
	printf("%8.5d| %%8.5d[512345]\n", 512345);
	printf("%.d| %%.d[512345]\n", 512345);
	printf("%.5d| %%.5d[512345]\n", 512345);
	printf("%.0d| %%.0d[51]\n", 51);
	printf("%.5d| %%.5d[51]\n", 51);
	printf("%.5s| %%.5s[he]\n", "he");
	printf("%.4s| %%.4s[hello world]\n", "hello world");
}
