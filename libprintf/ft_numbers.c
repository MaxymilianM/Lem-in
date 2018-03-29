/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:13:27 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/13 14:13:29 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_cp_help(t_print *puff, ssize_t a)
{
	(a < 0) ? ft_putchar('-') : 0;
	(a >= 0 && puff->n & FLAG_PLUS) ? ft_putchar('+') : 0;
	if (a > 0 && puff->n & FLAG_SPACE && !(puff->n & FLAG_PLUS))
		ft_putchar(' ');
}

static int			ft_count_space(t_print *puff, ssize_t a, int len, int l)
{
	char			symb;
	int				num;

	symb = ' ';
	if (!(puff->n & FLAG_MINUS))
	{
		(puff->n & FLAG_0 && !(puff->n & FLAG_PRS)) ? (symb = '0') : 0;
		(a < 0 && symb == '0') ? ft_putchar('-') : 0;
		if (a > 0 && puff->n & FLAG_SPACE && !(puff->n & FLAG_PLUS))
			ft_putchar(' ');
		(a >= 0 && puff->n & FLAG_PLUS && symb == '0') ? ft_putchar('+') : 0;
		if (puff->precision > 0)
			(puff->precision > len) ? (num = puff->width - puff->precision) :
				(num = ABS(puff->width - len));
		else
			num = ABS(puff->width - len);
		ft_print_space(num - l, symb, puff);
		(a < 0 && symb != '0') ? ft_putchar('-') : 0;
		(a >= 0 && puff->n & FLAG_PLUS && symb != '0') ? ft_putchar('+') : 0;
	}
	else
		ft_cp_help(puff, a);
	if (puff->precision > len)
		ft_print_space(puff->precision - len, '0', puff);
	return (0);
}

static int			ft_count_space_2(t_print *puff, ssize_t a, int len)
{
	int				l;
	int				num;

	l = 0;
	(a < 0 || puff->n & FLAG_PLUS || puff->n & FLAG_SPACE) ? (l = 1) : 0;
	if (puff->precision > 0)
		(puff->precision > len) ? (num = puff->width - puff->precision) :
			(num = ABS(puff->width - len));
	else
		num = ABS(puff->width - len);
	ft_print_space(num - l, ' ', puff);
	return (0);
}

static int			ft_check_null(size_t a, t_print *puff)
{
	if (a == 0)
	{
		if (puff->n & FLAG_0)
		{
			(puff->n & FLAG_SPACE) ? write(1, " ", 1) : 0;
			return (1);
		}
		else if ((puff->n & FLAG_PRS))
		{
			ft_print_space(puff->width, ' ', puff);
			return (0);
		}
	}
	return (1);
}

void				ft_int(t_print *puff)
{
	ssize_t			t;
	ssize_t			a;
	int				len;
	int				l;

	len = 0;
	l = 0;
	a = ft_format_int(puff);
	t = a;
	(t == 0) ? len++ : 0;
	while (t != 0)
	{
		t /= 10;
		len++;
	}
	if (ft_check_null(a, puff) == 0)
		return ;
	(a < 0 || puff->n & FLAG_PLUS || puff->n & FLAG_SPACE) ?
		((l = 1) && (puff->len++)) : 0;
	ft_count_space(puff, a, len, l);
	t = a;
	(a < -9223372036854775807) ? ft_putstr("9223372036854775808") :
		ft_putnbr(ABS(a));
	(puff->n & FLAG_MINUS) ? ft_count_space_2(puff, t, len) : 0;
	puff->len += len;
}
