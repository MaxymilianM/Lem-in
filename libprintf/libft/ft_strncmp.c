/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:31:28 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/05 12:31:31 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				rez;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	rez = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (i >= n)
			break ;
		rez = str1[i] - str2[i];
		if (rez != 0)
			return (rez);
		i++;
	}
	return (rez);
}
