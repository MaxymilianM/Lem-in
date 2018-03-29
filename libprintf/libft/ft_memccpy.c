/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:53:20 by mminenko          #+#    #+#             */
/*   Updated: 2017/10/25 18:53:22 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	ch;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	ch = (unsigned char)c;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s1[i] == ch)
			return (&s2[i + 1]);
		i++;
	}
	return (NULL);
}
