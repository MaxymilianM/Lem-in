/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:43:27 by mminenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:43:28 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				rez;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (s1 == s2)
		return (0);
	rez = 0;
	while (n > 0)
	{
		rez = *str1 - *str2;
		if (rez != 0)
			return (rez);
		str1++;
		str2++;
		n--;
	}
	return (rez);
}
