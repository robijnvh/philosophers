/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 09:01:17 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/31 09:01:18 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	size_t				i;
	size_t				m_len;

	if (!s)
		return (0);
	if (start > ft_strlen((char *)s) - 1)
		return (ft_strdup(""));
	if ((start + len) > ft_strlen((char *)s))
		m_len = (ft_strlen((char *)s) - start + 1);
	m_len = len + 1;
	substr = malloc(sizeof(*substr) * (m_len));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
