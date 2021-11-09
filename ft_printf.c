#include "ft_printf.h"

t_flags	*ft_initialise_flags(t_flags *flags)
{
	flags->sharp_option = 0;
	flags->justify_option = 0;
	flags->plus_option = 0;
	flags->width_option = 0;
	flags->zero_fill_option = 0;
	flags->space_option = 0;
	return (flags);
}

int	print_args(const char *s, va_list arg, t_flags *flags)
{
	if (*s == 'c')
		return (print_character(va_arg(arg, int), flags));
	else if (*s == 's')
		return (print_str(va_arg(arg, char *), flags));
	else if (*s == 'd' || *s == 'i')
		return (print_int_base_10(va_arg(arg, int), flags));
	else if (*s == 'u')
		return (print_unsigned_int(va_arg(arg, unsigned int), flags));
	else if (*s == 'x')
		return (print_int_base_16_to_lower(va_arg(arg, unsigned int), flags));
	else if (*s == 'X')
		return (print_int_base_16_to_upper(va_arg(arg, unsigned int), flags));
	else if (*s == 'p')
		return (print_pointer(va_arg(arg, unsigned long), flags));
	else if (*s == '%')
		return (print_percent(flags));
	return (0);
}

void	check_option(t_flags *flags, char *s, int *i)
{
	int	j;

	j = 2;
	while (j--)
	{
		if (s[*i + 1] == '-' || s[*i + 1] == '+')
		{
			if (s[*i + 1] == '+')
			{
				flags->plus_option = 1;
				(*i)++;
			}
			if (s[*i + 1] == '-')
			{
				flags->justify_option = 1;
				(*i)++;
			}
		}
	}
}

int	ft_print_count_and_parse_str(char *s, va_list arg)
{
	int		count;
	int		i;
	t_flags	*flags;
	int		shift;

	count = 0;
	i = 0;
	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
	{
		free(flags);
		return (0);
	}
	shift = 0;
	while (s[i])
	{
		flags = ft_initialise_flags(flags);
		if (s[i] == '%' && !ft_strchr(FLAGS, s[i + 1]))
		{
			while (s[i + 1] == ' ')
			{
				i++;
				flags->space_option = 1;
			}
			if (s[i + 1] == '#')
			{
				i++;
				flags->sharp_option = 1;
			}
			if (s[i + 1] == '0')
			{
				flags->zero_fill_option = 1;
				i++;
			}
			check_option(flags, s, &i);
			if (ft_strchr(FLAGS, s[i + 1]))
				count += print_args(s + i++ + shift + 1, arg, flags);
			else if (s[i + 1] > '0' && s[i + 1] <= '9')
			{
				 flags->width_option = ft_atoi(s + i + 1, &shift);
				 count += print_args(s + i + shift + 1, arg, flags);
				 i += shift + 1;
				 shift = 0;
			}
		}
		else if (s[i] == '%' && ft_strchr(FLAGS, s[i + 1]))
			count += print_args(s + i++ + 1, arg, flags);
		else
		{
			write(1, s + i, 1);
			count++;
		}
		i++;
	}
	free(flags);
	return (count);
}

int	ft_printf(const char *in, ...)
{
	va_list	arg;
	int		count_symbols;
	char	*input;

	count_symbols = 0;
	input = ft_strdup(in);
	va_start(arg, in);
	count_symbols = ft_print_count_and_parse_str(input, arg);
	va_end(arg);
	free(input);
	return (count_symbols);
}
