/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:03 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:54:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_args(const char *s, va_list arg)
{
	if (*s == 'c')
		return (print_character(va_arg(arg, int)));
	else if (*s == 's')
		return (print_str(va_arg(arg, char *)));
	else if (*s == 'd' || *s == 'i')
		return (print_int_base_10(va_arg(arg, int)));
	else if (*s == 'u')
		return (print_unsigned_int(va_arg(arg, unsigned int)));
	else if (*s == 'x')
		return (print_int_base_16_to_lower(va_arg(arg, unsigned int)));
	else if (*s == 'X')
		return (print_int_base_16_to_upper(va_arg(arg, unsigned int)));
	else if (*s == 'p')
		return (print_pointer(va_arg(arg, unsigned long)));
	else if (*s == '%')
		return (print_percent());
	return (0);
}

int	ft_print_count_and_parse_str(char *s, va_list arg)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr(FLAGS, s[i + 1]))
			count += print_args(s + i++ + 1, arg);
		else
		{
			write(1, s + i, 1);
			count++;
		}
		i++;
	}
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
