/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 10:32:58 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/30 10:32:59 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	count;
	unsigned int	index;

	if (!dst)
		return (0);
	if (!src)
		return (0);
	count = ft_strlen((char *)src);
	if (dstsize == 0)
		return (count);
	index = 0;
	while (src[index] != '\0' && index < (dstsize - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (count);
}
