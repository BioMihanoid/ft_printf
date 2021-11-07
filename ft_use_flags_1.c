#include "ft_printf.h"

int	print_character(char c, t_flags *flags)
{
	int count_space;
	if (flags->width_option <= 1)
	{
		write (1, &c, 1);
		return 1;
	}
	else
	{
		count_space = flags->width_option - 1;
		if (!flags->justify_option)
			while (count_space--)
				write(1, " ", 1);
		write (1, &c, 1);
		if (flags->justify_option)
			while (count_space--)
				write(1, " ", 1);
		return (flags->width_option);
	}
}

int	print_str(char *str, t_flags *flags)
{
	int	i;
	int count_space;

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
		count_space = flags->width_option - ft_strlen(str);
		if (!flags->justify_option)
			while (count_space--)
				write(1, " ", 1);
		while (str[i])
			write (1, &str[i++], 1);
		if (flags->justify_option)
			while (count_space--)
				write(1, " ", 1);
		return (flags->width_option);
	}
}

int	print_int_base_10(int nbr, t_flags *flags)
{
	int		count;
	char	*str;

	str = ft_itoa(nbr);
	count = print_str(str, flags);
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
