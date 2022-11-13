#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(){
	char s[100] = "hello world!";
	long max = LONG_MAX;
	long min = LONG_MIN;
	int n = printf("%p %p\n", max, min);
	printf("count : %d\n", n);
	int n2 = ft_printf("%p %p\n", max, min);
	printf("count : %d\n", n2);
}