/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:42:04 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/20 13:42:06 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_space_5(t_print *puff, int len)
{
	char		symb;
	int			num;

	if (!(puff->n & FLAG_MINUS))
	{
		(puff->n & FLAG_0 && !(puff->n & FLAG_PRS)) ? (symb = '0') :
			(symb = ' ');
		if (puff->precision > 0)
			(puff->precision > len) ? (num = puff->width - puff->precision) :
				(num = ABS(puff->width - len));
		else
			num = ABS(puff->width - len);
		if (puff->n & FLAG_SHARP && symb == '0')
			ft_putchar('0');
		ft_print_space(num, symb, puff);
		if (puff->n & FLAG_SHARP && symb == ' ')
			ft_putchar('0');
	}
	else if (puff->n & FLAG_SHARP)
		ft_putchar('0');
	if (puff->precision > len)
		ft_print_space(puff->precision - len, '0', puff);
	return (0);
}

static int		ft_check_null(size_t a, t_print *puff)
{
	if (a == 0)
	{
		if (puff->n & FLAG_SHARP)
		{
			if (!(puff->n & FLAG_MINUS))
				ft_print_space(puff->width, ' ', puff);
			ft_putchar('0');
			(puff->n & FLAG_MINUS) ? ft_print_space(puff->width, ' ', puff) : 0;
			puff->len++;
			return (0);
		}
		else if ((puff->n & FLAG_PRS) || (puff->n & FLAG_0))
		{
			ft_print_space(puff->width, ' ', puff);
			return (0);
		}
	}
	return (1);
}

void			ft_octal(t_print *puff)
{
	char		*str;
	size_t		a;
	size_t		t;
	int			len;

	len = 0;
	a = ft_format_hex(puff);
	(a == 0) ? len++ : 0;
	t = a;
	while (t != 0)
	{
		t /= 8;
		len++;
	}
	if (ft_check_null(a, puff) == 0)
		return ;
	if (puff->n & FLAG_SHARP)
		len += 1;
	ft_count_space_5(puff, len);
	str = ft_itoa_base(a, 8, 65);
	ft_putstr(str);
	free(str);
	(puff->n & FLAG_MINUS) ? ft_count_space_after(puff, len) : 0;
	puff->len += len;
}
