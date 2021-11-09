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

char	*ft_itoa_16_to_lower(unsigned int nbr)
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
			s[--len] = 'a' + (nbr % 16) % 10;
		else
			s[--len] = (nbr % 16) + '0';
		nbr /= 16;
	}
	return (s);
}
