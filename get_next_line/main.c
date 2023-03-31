#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

void change_array(int *t)
{
	t[0]++;
}
int main()
{
	char s[4];
	//close (2);
	//int	fd = open("test", O_RDONLY);
	//printf("%d", fd);

	int i = 0;
	while(i < 20)
	{
		s[i++] = 'l';
	}
	// printf("%s",get_next_line(fd)); 
}