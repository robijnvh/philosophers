/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 14:05:31 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/30 14:05:32 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tempdst;
	unsigned char	*tempsrc;
	size_t			i;

	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		if (tempdst[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
