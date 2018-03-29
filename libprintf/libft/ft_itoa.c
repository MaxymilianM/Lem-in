/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:01:49 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/12 14:31:10 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*sum_num(char *str, int n, size_t len)
{
	unsigned int	nb1;

	if (n == 0)
	{
		str[len] = 48;
		return (str);
	}
	nb1 = n;
	if (n < 0)
	{
		str[0] = ('-');
		nb1 = n * (-1);
	}
	while (nb1 > 0)
	{
		str[len] = (48 + nb1 % 10);
		nb1 = nb1 / 10;
		len--;
	}
	return (str);
}

char				*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	int				num;
	size_t			i;

	len = 0;
	i = 0;
	num = n;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	if (num <= 0)
		len++;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str = sum_num(str, num, len - 1);
	*(str + len) = '\0';
	return (str);
}
