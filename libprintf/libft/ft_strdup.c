/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:39:12 by mminenko          #+#    #+#             */
/*   Updated: 2017/10/24 11:39:24 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dust;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	dust = (char*)malloc(sizeof(char) * (len + 1));
	if (dust == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dust[i] = src[i];
		i++;
	}
	dust[i] = '\0';
	return (dust);
}
