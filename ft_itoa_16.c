/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:39 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:54:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_len_nbr(unsigned int n)
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

char	*ft_itoa_16(unsigned int nbr)
{
	char	*s;
	size_t	len;

	len = ft_len_nbr(nbr);
	s = (char *) malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (!nbr)
		s[0] = '0';
	while (nbr)
	{
		if (nbr % 16 >= 10 && nbr % 16 <= 15)
			s[--len] = 'A' + (nbr % 16) % 10;
		else
			s[--len] = (nbr % 16) + '0';
		nbr /= 16;
	}
	return (s);
}
