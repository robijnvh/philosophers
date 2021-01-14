/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:56:27 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/30 13:56:28 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tempdst;
	unsigned char	*tempsrc;
	size_t			i;

	if (!dst && !src)
		return (dst);
	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}
