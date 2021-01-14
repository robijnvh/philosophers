/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:37:34 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/30 12:37:35 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*res;

	res = malloc(size * count);
	if (!res)
		return (0);
	i = 0;
	while (i < (int)(count * size))
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
