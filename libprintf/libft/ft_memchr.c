/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:48:16 by mminenko          #+#    #+#             */
/*   Updated: 2017/10/29 15:48:18 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		u;
	unsigned char		*str;
	size_t				i;

	i = 0;
	str = (unsigned char *)s;
	u = c;
	while (n > 0)
	{
		if (*str == u)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
