/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:07:51 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/14 13:07:52 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_hex(long long n)
{
	long long	res;

	if (n > 0)
	{
		ft_print_hex(n / 16);
		res = n % 16;
		if (res > 9)
		{
			res = res - 10;
			ft_putchar(97 + res);
		}
		else
			ft_putnbr(res);
	}
}
