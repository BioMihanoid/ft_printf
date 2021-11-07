/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:00:41 by gmilan            #+#    #+#             */
/*   Updated: 2021/10/10 16:40:26 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static int	ft_help_result(int check_sign)
{
	if (!check_sign)
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str, int *length)
{
	size_t				i;
	int					check_sign;
	unsigned long long	res;
	int					count_number;

	i = 0;
	check_sign = 0;
	res = 0;
	*length = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			check_sign = 1;
	count_number = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (count_number > 19 && check_sign)
			return (0);
		if (count_number++ > 19)
			return (-1);
		res = res * 10 - (str[i] - '0');
		i++;
		(*length)++;
	}
	if (check_sign)
		(*length)++;
	return (res * ft_help_result(check_sign));
}
