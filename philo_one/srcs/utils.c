/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 13:38:40 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/22 13:51:29 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

char	*ft_strdup(const char *src)
{
	int			i;
	char		*copy;
	int			len;

	len = 0;
	i = 0;
	if (!src)
		copy = (char*)src;
	while (src[i] != '\0')
	{
		i++;
		len++;
	}
	copy = (char *)malloc(sizeof(*src) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

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

static int		length(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = length(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	i = i - 1;
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
