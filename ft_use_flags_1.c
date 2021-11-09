#include "ft_printf.h"

void	fill_missing_space(char filer, int count_space)
{
	while (count_space--)
		write(1, &filer, 1);
}

int	print_character(char c, t_flags *flags)
{
	char filer;

	if (!flags->zero_fill_option)
		filer = ' ';
	else
		filer = '0';
	if (flags->width_option < 2)
	{
		write (1, &c, 1);
		return (1);
	}
	else
	{
		if (!flags->justify_option)
			fill_missing_space(filer, flags->width_option - 1);
		write (1, &c, 1);
		if (flags->justify_option)
			fill_missing_space(filer, flags->width_option - 1);
		return (flags->width_option);
	}
}

int	print_str(char *str, t_flags *flags)
{
	int	i;
	char filer;

	if (!flags->zero_fill_option)
		filer = ' ';
	else
		filer = '0';
	i = 0;
	if (!str)
	{
		print_str("(null)", flags);
		return (6);
	}
	if (ft_strlen(str) >= flags->width_option)
	{
		while (str[i])
			write (1, &str[i++], 1);
		return (i);
	}
	else
	{
		if (flags->plus_option)
			write (1, &str[i++], 1);
		if (flags->zero_fill_option && str[i] == '-')
			write (1, &str[i++], 1);
		if (!flags->justify_option)
			fill_missing_space(filer, flags->width_option - ft_strlen(str));
		while (str[i])
			write (1, &str[i++], 1);
		if (flags->justify_option)
			fill_missing_space(filer, flags->width_option - ft_strlen(str));
		return (flags->width_option);
	}
}

int	print_int_base_10(int nbr, t_flags *flags)
{
	int		count;
	char	*str;

	count = 0;
	if (flags->space_option && nbr >= 0 && !flags->width_option &&
	!flags->justify_option && !flags->zero_fill_option && !flags->plus_option
	&& !flags->sharp_option)
	{
		write(1, " ", 1);
		count++;
	}
	str = ft_itoa(nbr, flags->plus_option);
	count += print_str(str, flags);
	free(str);
	return (count);
}

int	print_unsigned_int(unsigned int nbr, t_flags *flags)
{
	int		count;
	char	*str;

	str = ft_utoa(nbr);
	count = print_str(str, flags);
	free(str);
	return (count);
}

int	print_pointer(unsigned long nbr, t_flags *flags)
{
	int		count;
	char	*str;

	str = ft_ultoa_16(nbr);
	count = print_str(str, flags);
	free(str);
	return (count);
}
