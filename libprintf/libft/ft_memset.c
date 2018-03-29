/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:20 by mminenko          #+#    #+#             */
/*   Updated: 2017/10/25 18:48:23 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	g;

	g = (unsigned char)c;
	p = (unsigned char *)b;
	while (len > 0)
	{
		*p = g;
		p++;
		len--;
	}
	return (b);
}
