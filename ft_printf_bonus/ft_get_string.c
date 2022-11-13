#include "ft_printf.h"

char *ft_get_string(char *s, int *flags){
	if(!s)
		s = "(null)";
	//int strlen = ft_strlen(s);
	char * new_string = 0;
	if(ft_flags_contain(flags, '.'))
	{
		return (ft_substr(s,0, ft_get_flag_count(flags, '.')));
	}
	/*else{
	 	new_string = ft_strdup(s);
		char * join = 0;
		n -= strlen;
		char *spaces = 0;
		
		if(n > 0)
		{
			spaces = malloc(n + 1);
			spaces[n] = '\0';
			int i = 0;
			while(spaces[i])
				spaces[i++] = ' ';
			if(!ft_flags_contain(flags, '-'))
			{
				if(spaces)
					join = ft_strjoin(spaces, new_string);
			}
			else
			{
				if(spaces)
					join = ft_strjoin(new_string, spaces);
			}
			if(join){
				free(new_string);
				return (join);
			}
		}
	}*/
	return(new_string);
}