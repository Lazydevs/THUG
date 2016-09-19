#include <LZ/string_utils.h>

void 		put_char(char c)
{
	write(1, &c, 1);
}

void		put_str(const char *str)
{
	write(1, str, str_len(str));
}

void		put_nbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		put_char('-');
	}
	if (n < 10)
	{
		put_char(n + '0');
	}
	if (n >= 10)
	{
		put_nbr(n / 10);
		put_nbr(n % 10);
	}
}

int			str_len(const char *str)
{
	int		i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str && str[++i]);
	return (i);
}

char		*str_concat(char *str1, char *str2)
{
	int		ln1;
	int		ln2;
	int		i;
	int		j;
	char	*result;

	ln1 = str_len(str1);
	ln2 = str_len(str2);
	i = 0;
	j = 0;
	if ((result = (char *)malloc(sizeof(char) * (ln1 + ln2 + 1))) == NULL)
		return (NULL);
	result[ln1 + ln2] = '\0';
	while (i < ln1)
	{
		result[i] = str1[i];
		i++;
	}
	while (j < ln2)
		result[i + j] = str2[j++];
	return (result);
}
