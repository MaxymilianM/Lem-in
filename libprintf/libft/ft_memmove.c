/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:24:13 by mminenko          #+#    #+#             */
/*   Updated: 2017/10/25 19:24:15 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	if (s1 < s2)
	{
		while (len > 0)
		{
			s2[len - 1] = s1[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (s2);
}
