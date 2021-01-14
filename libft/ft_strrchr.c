/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 09:00:28 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/10/30 09:00:29 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = (0);
	while (*str)
	{
		if (*str == c)
			ptr = (char *)str;
		str++;
	}
	if (ptr)
		return (ptr);
	if (c == '\0')
		return ((char *)str);
	return (0);
}
