/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:40:29 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/11 18:40:30 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_str_sp(t_print *puff, int len, char symb)
{
	int				num;

	num = 0;
	(puff->n & FLAG_0) ? (symb = '0') : 0;
	if (!(puff->n & FLAG_MINUS))
	{
		if (puff->precision > 0)
			(puff->precision < len) ? (num = puff->width - puff->precision) :
				(num = ABS(puff->width - len));
		else if (puff->width > len && !(puff->n & FLAG_PRS))
			num = puff->width - len;
		else if (puff->width > len && (puff->n & FLAG_PRS))
			num = puff->width;
		ft_print_space(num, symb, puff);
	}
	else
	{
		if (puff->precision > 0)
			(puff->precision < len) ? (num = puff->width - puff->precision) :
				(num = ABS(puff->width - len));
		else if (puff->width > len)
			num = ABS(puff->width - len);
		ft_print_space(num, ' ', puff);
	}
}

void				ft_string(t_print *puff)
{
	char			*s;
	int				len;
	int				tmp;

	if ((s = va_arg(puff->ap, char*)) == NULL)
	{
		ft_putstr("(null)");
		puff->len += 6;
		return ;
	}
	len = ft_strlen(s);
	(puff->width > 0 && !(puff->n & FLAG_MINUS)) ? ft_str_sp(puff, len, 32) : 0;
	(puff->n & FLAG_PRS) ? (tmp = puff->precision) :
		(tmp = len);
	while (*s && tmp > 0)
	{
		write(1, s, 1);
		s++;
		tmp--;
		puff->len++;
	}
	(puff->width > 0 && (puff->n & FLAG_MINUS)) ? ft_str_sp(puff, len, 32) : 0;
}

void				ft_char(t_print *puff)
{
	int				c;
	char			symb;

	symb = ' ';
	(puff->n & FLAG_0) ? (symb = '0') : 0;
	if (puff->n & MODIF_L)
	{
		ft_wchar(puff);
		return ;
	}
	c = va_arg(puff->ap, int);
	puff->len++;
	if (puff->width > 0 && !(puff->n & FLAG_MINUS))
		ft_print_space(puff->width - 1, symb, puff);
	ft_putchar(c);
	if (puff->width > 0 && (puff->n & FLAG_MINUS))
		ft_print_space(puff->width - 1, ' ', puff);
}

int					ft_byte_s(unsigned int value)
{
	int				size;

	size = ft_size_bin(value);
	if (size <= 7)
		size = 1;
	else if (size <= 11)
		size = 2;
	else if (size <= 16)
		size = 3;
	else
		size = 4;
	return (size);
}

void				ft_wchar(t_print *puff)
{
	unsigned int	c;
	int				s_byte;

	c = va_arg(puff->ap, unsigned int);
	s_byte = ft_byte_s(c);
	puff->len += s_byte;
	if (puff->width > 0 && !(puff->n & FLAG_MINUS))
		ft_print_space(puff->width - s_byte, ' ', puff);
	ft_unicode(c);
	if (puff->width > 0 && (puff->n & FLAG_MINUS))
		ft_print_space(puff->width - s_byte, ' ', puff);
}
