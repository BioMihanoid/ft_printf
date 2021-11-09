#include "ft_printf.h"

int	print_int_base_16_to_lower(unsigned int n, t_flags *flags)
{
	int		count;
	char	*str;

	if (flags->sharp_option && n != 0)
		str = ft_ultoa_16(n);
	else
		str = ft_itoa_16_to_lower(n);
	count = print_str(str, flags);
	free(str);
	return (count);
}

int	print_int_base_16_to_upper(unsigned int n, t_flags *flags)
{
	int		count;
	char	*str;

	if (flags->sharp_option && n != 0)
		str = ft_ultoa_16_to_upper(n);
	else
		str = ft_itoa_16(n);
	count = print_str(str, flags);
	free(str);
	return (count);
}

int	print_percent(t_flags *flags)
{
	return (print_character('%', flags));
}
