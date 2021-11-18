/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_flags_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:29 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:54:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_int_base_16_to_lower(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa_16_to_lower(n);
	count = print_str(str);
	free(str);
	return (count);
}

int	print_int_base_16_to_upper(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa_16(n);
	count = print_str(str);
	free(str);
	return (count);
}

int	print_percent(void)
{
	return (print_character('%'));
}
