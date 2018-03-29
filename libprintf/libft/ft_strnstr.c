/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:43:27 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/03 20:43:28 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *htack, const char *needle, size_t len)
{
	int		i;
	int		z;
	int		size_needle;
	size_t	u;

	z = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char*)htack);
	size_needle = ft_strlen(needle);
	u = 0;
	while (htack[u] != '\0' && len >= (u + size_needle))
	{
		while (needle[z] == htack[u + z])
		{
			if (z == size_needle - 1)
				return ((char*)htack + u);
			z++;
		}
		z = 0;
		u++;
	}
	return (NULL);
}
