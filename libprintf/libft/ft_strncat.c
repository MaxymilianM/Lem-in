/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:33:31 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/03 17:33:32 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	u;
	size_t	k;

	k = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[k] != '\0')
		k++;
	if (n > k)
		n = k;
	u = i + n;
	j = 0;
	while (i < u)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
