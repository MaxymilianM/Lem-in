/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:13:32 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/20 14:13:36 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*sum_num(char *str, size_t n, int *len, int base)
{
	size_t			nb1;

	len[0] -= 1;
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	nb1 = n;
	while (nb1 > 0)
	{
		if ((nb1 % base) >= 10)
			str[len[0]] = len[1] + (nb1 % base) - 10;
		else
			str[len[0]] = (48 + nb1 % base);
		nb1 = nb1 / base;
		len[0]--;
	}
	return (str);
}

char				*ft_itoa_base(size_t n, int base, int registr)
{
	int				len[2];
	char			*str;
	size_t			num;
	size_t			i;

	len[0] = 0;
	len[1] = registr;
	i = 0;
	num = n;
	while (n != 0)
	{
		n = n / base;
		len[0]++;
	}
	if (num == 0)
		len[0]++;
	str = ft_strnew(len[0]);
	if (str == NULL)
		return (NULL);
	str = sum_num(str, num, len, base);
	return (str);
}
