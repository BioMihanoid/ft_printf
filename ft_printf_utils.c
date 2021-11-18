/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:50:56 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:51:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return ((void *)0);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*s;

	len = ft_strlen(s1);
	s = (char *)malloc(len + 1);
	i = 0;
	if (s)
	{
		while (i < len + 1)
		{
			s[i] = (char)s1[i];
			i++;
		}
	}
	return (s);
}

int	ft_strlen(const	char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
