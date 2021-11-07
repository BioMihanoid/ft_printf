/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:00:41 by gmilan            #+#    #+#             */
/*   Updated: 2021/10/09 15:47:56 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

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
