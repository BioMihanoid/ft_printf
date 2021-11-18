/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:55:24 by                   #+#    #+#             */
/*   Updated: 2021/11/11 18:55:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# define FLAGS "cspdiuxX%"

int		ft_printf(const char *in, ...);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const	char *s);
char	*ft_utoa(unsigned int nbr);
char	*ft_itoa(int n);
char	*ft_itoa_16(unsigned int nbr);
char	*ft_itoa_16_to_lower(unsigned int nbr);
char	*ft_ultoa_16(unsigned long nbr);
char	*ft_ultoa_16_to_upper(unsigned long nbr);
int		ft_atoi(const char *str);
int		print_str(char *str);
int		print_int_base_16_to_upper(unsigned int n);
int		print_int_base_16_to_lower(unsigned int n);
int		print_character(char c);
int		print_int_base_10(int nbr);
int		print_pointer(unsigned long nbr);
int		print_unsigned_int(unsigned int nbr);
int		print_percent(void);

#endif