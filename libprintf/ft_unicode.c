/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:28:54 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/11 18:28:59 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_size_bin(wchar_t value)
{
	unsigned int	size;

	size = 0;
	while (value != 0)
	{
		value /= 2;
		size++;
	}
	return (size);
}

static void			ft_size_else(unsigned int v, unsigned char octet)
{
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned int	mask3;

	mask3 = 4034953344;
	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
}

static void			ft_size_16(unsigned int v)
{
	unsigned char	octet;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned int	mask2;

	mask2 = 14712960;
	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
}

static void			ft_size_11(unsigned int v)
{
	unsigned char	octet;
	unsigned char	o2;
	unsigned char	o1;
	unsigned int	mask1;

	mask1 = 49280;
	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
}

void				ft_unicode(unsigned int symbol)
{
	int				size;
	wchar_t			value;
	unsigned char	octet;

	value = symbol;
	size = ft_size_bin(value);
	if (size <= 7)
	{
		octet = value;
		write(1, &octet, 1);
	}
	else if (size <= 11)
		ft_size_11(value);
	else if (size <= 16)
		ft_size_16(value);
	else
		ft_size_else(value, 0);
}
