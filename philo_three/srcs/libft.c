/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 12:09:31 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/27 13:27:13 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

static long int	ft_amax(const char *str, unsigned long int res, int sign, int i)
{
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if ((res > 922337203685477580 || res == 922337203685477580)
		&& ((str[i] - '0') > 7) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || res == 922337203685477580)
		&& ((str[i] - '0') > 8) && sign == -1)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int				ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str[i])
		return (0);
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && sign != -1)
		i++;
	res = ft_amax(str, res, sign, i);
	return ((int)res * sign);
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
