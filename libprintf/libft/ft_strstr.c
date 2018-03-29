/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:12:22 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/03 20:12:25 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int z;
	int size_needle;

	z = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	size_needle = ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		while (needle[z] == haystack[i + z])
		{
			if (z == size_needle - 1)
				return ((char*)haystack + i);
			z++;
		}
		z = 0;
		i++;
	}
	return (NULL);
}
