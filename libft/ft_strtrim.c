/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:53 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/11/23 12:57:56 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*trim;

	if (!s1)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && !ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen((char *)&s1[i]);
	if (len != 0)
	{
		while (s1[i + len - 1] && !ft_strchr(set, s1[i + len - 1]))
			len--;
	}
	trim = (char *)malloc(len + 1);
	if (!trim)
		return (NULL);
	trim = ft_memcpy((void *)trim, (const void *)&s1[i], (size_t)len);
	trim[len] = '\0';
	return (trim);
}
