/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:58:43 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/06 16:58:44 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	u;
	size_t	i;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u = ft_strlen(s1);
	k = ft_strlen(s2);
	i = u + k;
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
