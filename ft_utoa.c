/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:34 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:54:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_len_nbr(unsigned int n)
{
	size_t	count;

	count = 1;
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_utoa(unsigned int nbr)
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
		s[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (s);
}
