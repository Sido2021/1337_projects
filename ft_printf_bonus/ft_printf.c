#include "ft_printf.h"

void	init_flags(int *flags){
	int i = 0;
	while(i < 7)
		flags[i++] = -1;
}
int get_step(const char *s)
{
	int to = 0;
	while(ft_isdigit(s[to]))
		to++;
	return to;
}

int get_number(const char *s, int to){
	char *sb = ft_substr(s, 0, to);
	int n = ft_atoi(sb);
	free(sb);
	return n;
}

int	ft_printf(const char *s, ...)
{
	va_list	vars;
	int		count;
	int		n;
	int flags[7];

	count = 0;
	init_flags(flags);
	va_start(vars, s);
	while (*s)
	{
		if (*s++ == '%'){
			init_flags(flags);
			while(*s == '-' || *s == '.' || *s == '#' || *s == ' ' || *s == '+' || ft_isdigit(*s)){
				int pos = 0;
				if(*s == '-' ){
					flags[1] = 0;
					s++;
					continue;
				}
				else if(*s == '0' ){
					flags[2] = 0;
					s++;
					continue;
				}
				else if(*s == '.')
					pos = 3;
				else if(*s == '#' ){
					flags[4] = 0;
					s++;
					continue;
				}
				else if(*s == ' ' ){
					flags[5] = 0;
					s++;
					continue;
				}
				else if(*s == '+'){
					flags[6] = 0;
					s++;
					continue;
				}
				flags[pos] = 0;
				if(pos != 0)
					s++;
				if(ft_isdigit(*s))
				{
					int to = get_step(s);
					n = get_number(s,  to);
					flags[pos] = n;
					s += to;
				}
			}
			count += ft_print_arg(*s, vars, flags);
			s++;
			continue;
		}
		ft_put_char(*(s - 1));
		count++;
	}

	va_end(vars);
	return (count);
}