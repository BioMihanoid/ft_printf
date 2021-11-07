#include "ft_printf.h"

int	print_int_base_16_to_lower(unsigned int n, t_flags *flags)
{
	char	*s;
	int		i;

	s = ft_itoa_16(n);
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += ('a' - 'A');
		print_character(s[i++], flags);
	}
	free(s);
	return (i);
}

int	print_int_base_16_to_upper(unsigned int n, t_flags *flags)
{
	int		count;
	char	*str;

	str = ft_itoa_16(n);
	count = print_str(str, flags);
	free(str);
	return (count);
}

int print_percent(t_flags *flags)
{
	return (print_character('%', flags));
}
