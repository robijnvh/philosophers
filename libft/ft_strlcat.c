/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 10:21:32 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/30 10:21:32 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dlen;
	size_t		slen;
	size_t		index;

	dlen = ft_strlen((char *)dst);
	slen = ft_strlen((char *)src);
	index = 0;
	if (dstsize == 0)
		return (0);
	if (dstsize <= dlen)
		slen = slen + dstsize;
	else
		slen = slen + dlen;
	while (src[index] != '\0' && dlen < (dstsize - 1) && dst != src)
	{
		dst[dlen] = src[index];
		dlen++;
		index++;
	}
	dst[dlen] = '\0';
	return (slen);
}
