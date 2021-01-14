/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 09:37:40 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/30 09:37:41 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		i_n;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			i_n = 1;
			while (needle[i_n] != '\0' &&
			haystack[i + i_n] == needle[i_n] && (size_t)(i + i_n) < len)
				i_n++;
			if (needle[i_n] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
