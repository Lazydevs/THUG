#ifndef STRING_UTILS_H
# define STRING_UTILS_H
# include <unistd.h>
# include <stdlib.h>

void 		put_char(char c);
void		put_str(const char *str);
void		put_nbr(int nb);
int			str_len(const char *str);
char		*str_concat(char *str1, char *str2);

#endif
