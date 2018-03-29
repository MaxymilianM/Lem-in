/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:13:58 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/08 13:03:43 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_p(char const *s)
{
	size_t		len;

	len = 0;
	while ((s[len] == ' ' || s[len] == '\t' ||
					s[len] == '\n') && (s[len] != '\0'))
		len++;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		start;
	size_t		string;
	size_t		u;
	size_t		cool_str;

	if (s == NULL)
		return (NULL);
	string = ft_strlen(s);
	start = split_p(s);
	if (start == string)
		return (ft_strnew(1));
	while (s[string] == ' ' || s[string] == '\t' ||
					s[string] == '\n' || s[string] == '\0')
		string--;
	cool_str = string - start + 1;
	str = ft_strnew(cool_str);
	if (str == NULL)
		return (NULL);
	u = 0;
	while (u < cool_str)
		str[u++] = s[start++];
	str[u] = '\0';
	return (str);
}
