/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:25 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:54:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_len_nbr(unsigned long n)
{
	size_t	count;

	count = 1;
	while (n > 15)
	{
		count++;
		n /= 16;
	}
	return (count);
}

char	*ft_ultoa_16(unsigned long nbr)
{
	char	*s;
	size_t	len;

	len = ft_len_nbr(nbr);
	if (!len)
		return (NULL);
	s = (char *) malloc(len + 3);
	if (!s)
		return (NULL);
	s[len + 2] = '\0';
	if (!nbr)
		s[2] = '0';
	while (nbr)
	{
		if (nbr % 16 >= 10 && nbr % 16 <= 15)
			s[--len + 2] = 'a' + (nbr % 16) % 10;
		else
			s[--len + 2] = (nbr % 16) + '0';
		nbr /= 16;
	}
	s[0] = '0';
	s[1] = 'x';
	return (s);
}
