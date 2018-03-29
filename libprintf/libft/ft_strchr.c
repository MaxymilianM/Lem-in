/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:38:15 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/03 19:38:18 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	k;

	k = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == k)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == k)
		return ((char*)s + i);
	return (NULL);
}
