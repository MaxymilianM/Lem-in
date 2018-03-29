/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:49:06 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/08 13:03:11 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*word(const char *s, size_t start, size_t len, char c)
{
	size_t		u;
	char		*str;

	u = 0;
	if (s[start] == '\0')
		return (NULL);
	str = ft_strnew(len - start);
	if (str == NULL)
		return (NULL);
	while (s[start] != c && s[start] != '\0')
		str[u++] = s[start++];
	str[u] = '\0';
	return (str);
}

static size_t	count_words(char const *s, char c)
{
	size_t		cnt;
	size_t		len;
	size_t		u;

	len = 0;
	cnt = 0;
	while (s[len] != '\0')
	{
		u = 0;
		while (s[len] == c && s[len] != '\0')
			len++;
		while (s[len] != c && s[len] != '\0')
		{
			len++;
			u = 1;
		}
		cnt = cnt + u;
	}
	return (cnt);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**go_home;
	size_t		len;
	size_t		u;
	size_t		start;
	size_t		words_cnt;

	if (s == NULL)
		return (NULL);
	u = 0;
	len = 0;
	words_cnt = count_words(s, c);
	go_home = (char**)malloc(sizeof(char*) * (words_cnt + 2));
	if (go_home == NULL)
		return (NULL);
	while (s[len] != '\0')
	{
		while (s[len] == c && s[len] != '\0')
			len++;
		start = len;
		while (s[len] != c && s[len] != '\0')
			len++;
		go_home[u++] = word(s, start, len, c);
	}
	go_home[u] = NULL;
	return (go_home);
}
