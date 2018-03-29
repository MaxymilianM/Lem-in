/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:53:34 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/01 12:53:36 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		checker(const char *str, int result, char c, size_t *doble)
{
	char		*s1;
	int			rez;
	size_t		a;
	size_t		len;

	a = doble[0];
	len = doble[1];
	if (len > 19 && c == '-')
		return (0);
	else if (len > 19)
		return (-1);
	s1 = "9223372036854775807";
	rez = ft_strncmp(str + a, s1, len);
	if (rez == 0 && c == '-')
		return (1);
	else if (rez == 0)
		return (-1);
	if (rez > 0 && c == '-')
		return (0);
	else if (rez > 0)
		return (-1);
	return (result);
}

static size_t	space_check(const char *str, size_t a)
{
	while (str[a] == 32 || str[a] == '\t' || str[a] == '\n' ||
					str[a] == '\r' || str[a] == '\f' || str[a] == '\v')
		a++;
	return (a);
}

int				ft_atoi(const char *str)
{
	int			result;
	size_t		a;
	size_t		next_start;
	size_t		start;
	size_t		doble[2];

	result = 0;
	a = 0;
	a = space_check(str, a);
	start = a;
	if (str[a] == '+' || str[a] == '-')
		a++;
	if (str[a] < 48 || str[a] > 57)
		return (0);
	next_start = a;
	while (str[a] > 47 && str[a] < 58 && str[a] != '\0')
		result = result * 10 + str[a++] - 48;
	doble[0] = next_start;
	doble[1] = (a - next_start);
	if ((a - next_start) > 18)
		result = checker(str, result, str[start], doble);
	if (str[start] == '-')
		return (result * -1);
	return (result);
}
