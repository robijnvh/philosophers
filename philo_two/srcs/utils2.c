/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:43:29 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/22 13:54:56 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

static int		ft_len(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		res;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = len1 + len2 + 1;
	return (res);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		i2;

	if (!s1 || !s2 || (!s1 && !s2))
		return (0);
	newstr = (char *)malloc(sizeof(char *) * (ft_len((char *)s1, (char *)s2)));
	if (!newstr)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
	{
		newstr[i] = s2[i2];
		i++;
		i2++;
	}
	newstr[i] = '\0';
	return (newstr);
}

size_t			ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void			ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	char	y;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
	{
		y = 48 + n;
		write(fd, &y, 1);
	}
}
