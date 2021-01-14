/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:48:14 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/11/05 13:48:15 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = (lst)->next;
		count++;
	}
	return (count);
}
