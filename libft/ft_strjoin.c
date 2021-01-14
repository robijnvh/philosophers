/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:05:25 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/11/01 11:05:26 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
