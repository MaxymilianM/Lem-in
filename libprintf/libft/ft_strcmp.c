/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:47:13 by mminenko          #+#    #+#             */
/*   Updated: 2017/10/23 19:47:14 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				rez;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	rez = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		rez = str1[i] - str2[i];
		if (rez != 0)
			return (rez);
		i++;
	}
	return (rez);
}
