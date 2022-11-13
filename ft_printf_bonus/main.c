#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(){
	// char s[100] = "hello world!";
	// long max = LONG_MAX;
	// long min = LONG_MIN;
	// int n = printf("%p %p\n", max, min);
	// printf("count : %d\n", n);
	// int n2 = ft_printf("%p %p\n", max, min);
	// printf("count : %d\n", n2);

	char s[20] = "hello";
	long num = LONG_MAX;

	/*int n = printf("%#.5x", 255);
	printf("|n\n%d\n",n);
	n = ft_printf("%#.5x", 255);;*/

	/*int n = printf("%0#5x", 255);
	printf("|n\n%d\n",n);
	n = ft_printf("%0#5x", 255);*/

	/*int n = printf("%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("|n\n%d\n",n);
	n = ft_printf("%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);*/
	
	int n = printf("%+.0d", 0);
	printf("|n\n%d\n",n);
	n = ft_printf("%+.0d", 0);

	printf("|n\n%d\n",n);
}