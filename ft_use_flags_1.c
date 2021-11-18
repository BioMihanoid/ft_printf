/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_flags_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:15 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:54:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_character(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_str("(null)"));
	while (str[i])
		write (1, &str[i++], 1);
	return (i);
}

int	print_int_base_10(int nbr)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(nbr);
	count += print_str(str);
	free(str);
	return (count);
}

int	print_unsigned_int(unsigned int nbr)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_utoa(nbr);
	count = print_str(str);
	free(str);
	return (count);
}

int	print_pointer(unsigned long nbr)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_ultoa_16(nbr);
	count = print_str(str);
	free(str);
	return (count);
}
