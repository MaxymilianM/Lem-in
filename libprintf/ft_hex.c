/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:11:05 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/17 17:11:07 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_space_4(t_print *puff, int len)
{
	char		symb;
	int			num;

	symb = ' ';
	if (!(puff->n & FLAG_MINUS))
	{
		(puff->n & FLAG_0 && !(puff->n & FLAG_PRS)) ? (symb = '0') : 0;
		if (puff->precision > 0)
			(puff->precision > len) ? (num = puff->width - puff->precision) :
		(num = ABS(puff->width - len));
		else
			num = ABS(puff->width - len);
		if (puff->n & FLAG_SHARP && symb == '0')
			puff->n & SPECIFIC_BX ? ft_putstr("0X") : ft_putstr("0x");
		ft_print_space(num, symb, puff);
		if (puff->n & FLAG_SHARP && symb == ' ')
			puff->n & SPECIFIC_BX ? ft_putstr("0X") : ft_putstr("0x");
	}
	else if (puff->n & FLAG_SHARP)
		puff->n & SPECIFIC_BX ? ft_putstr("0X") : ft_putstr("0x");
	(puff->n & FLAG_SHARP) ? (len -= 2) : 0;
	if (puff->precision > len)
		ft_print_space(puff->precision - len, '0', puff);
	return (0);
}

int				ft_count_space_after(t_print *puff, int len)
{
	int			num;

	if (puff->precision > 0)
		(puff->precision > len) ? (num = puff->width - puff->precision) :
	(num = ABS(puff->width - len));
	else
		num = ABS(puff->width - len);
	ft_print_space(num, ' ', puff);
	return (0);
}

size_t			ft_format_hex(t_print *puff)
{
	size_t		a;

	if (puff->n & MODIF_LL)
		a = (unsigned long long int)va_arg(puff->ap, unsigned long long int);
	else if (puff->n & MODIF_Z)
		a = (size_t)va_arg(puff->ap, size_t);
	else if (puff->n & MODIF_L)
		a = (unsigned long int)va_arg(puff->ap, unsigned long int);
	else if (puff->n & MODIF_HH)
		a = (unsigned char)va_arg(puff->ap, int);
	else if (puff->n & MODIF_H)
		a = (unsigned short)va_arg(puff->ap, int);
	else if (puff->n & MODIF_J)
		a = (uintmax_t)va_arg(puff->ap, uintmax_t);
	else
		a = (unsigned int)va_arg(puff->ap, unsigned int);
	return (a);
}

static int		ft_check_null(size_t a, t_print *puff)
{
	if (a == 0)
	{
		if (puff->n & SPECIFIC_P)
			return (1);
		else if ((puff->n & FLAG_PRS) || (puff->n & FLAG_0))
		{
			ft_print_space(puff->width, ' ', puff);
			return (0);
		}
		else if (puff->n & FLAG_SHARP)
		{
			if (!(puff->n & FLAG_MINUS))
				ft_print_space(puff->width, ' ', puff);
			ft_putchar('0');
			(puff->n & FLAG_MINUS) ? ft_print_space(puff->width, ' ', puff) : 0;
			puff->len++;
			return (0);
		}
	}
	return (1);
}

void			ft_hex(t_print *puff)
{
	char		*str;
	size_t		a;
	size_t		t;
	int			len;

	a = ft_format_hex(puff);
	t = a;
	len = (t == 0) ? 1 : 0;
	while (t != 0)
	{
		t /= 16;
		len++;
	}
	if (ft_check_null(a, puff) == 0)
		return ;
	(puff->n & FLAG_SHARP) ? (len += 2) : 0;
	ft_count_space_4(puff, len);
	if (puff->n & SPECIFIC_BX)
		str = ft_itoa_base(a, 16, 65);
	else
		str = ft_itoa_base(a, 16, 97);
	ft_putstr(str);
	(puff->n & FLAG_MINUS) ? ft_count_space_after(puff, len) : 0;
	free(str);
	puff->len += len;
}
