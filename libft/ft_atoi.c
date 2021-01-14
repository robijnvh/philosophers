/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:12:23 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/28 15:12:24 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
