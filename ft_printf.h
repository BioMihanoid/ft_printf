#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# define FLAGS "cspdiuxX%"

typedef struct	s_flags
{
	int	width_option;
	int	justify_option;
	int	zero_fill_option;
	int	plus_option;
	int	sharp_option;
	int	space_option;
}	t_flags;

int		ft_printf(const char *in, ...);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const	char *s);
char	*ft_utoa(unsigned int nbr);
char	*ft_itoa(int n, int plus_option);
char	*ft_itoa_16(unsigned int nbr);
char	*ft_itoa_16_to_lower(unsigned int nbr);
char	*ft_ultoa_16(unsigned long nbr);
char	*ft_ultoa_16_to_upper(unsigned long nbr);
int		ft_atoi(const char *str, int *length);
int		print_str(char *str, t_flags *flags);
int		print_int_base_16_to_upper(unsigned int n, t_flags *flags);
int		print_int_base_16_to_lower(unsigned int n, t_flags *flags);
int		print_character(char c, t_flags *flags);
int		print_int_base_10(int nbr, t_flags *flags);
int		print_pointer(unsigned long nbr, t_flags *flags);
int		print_unsigned_int(unsigned int nbr, t_flags *flags);
int		print_percent(t_flags *flags);

#endif