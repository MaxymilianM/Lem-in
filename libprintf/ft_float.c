/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:30:18 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/23 18:30:20 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_prnt_s(ssize_t digt, t_print *puff, int tmp, char symb)
{
	int				len;
	ssize_t			h;

	(puff->n & FLAG_PRS) ? (tmp = puff->precision) : 0;
	(puff->n & FLAG_0) ? (symb = '0') : 0;
	(digt < 0 && (puff->n & FLAG_0)) ? ft_putchar('-') : 0;
	if ((digt >= 0) && (puff->n & FLAG_PLUS) && (puff->n & FLAG_0))
		ft_putchar('+');
	len = 0;
	h = digt;
	while (h != 0)
	{
		h /= 10;
		len++;
	}
	(digt < 0 || (puff->n & FLAG_PLUS) || (puff->n & FLAG_SPACE)) ? len++ : 0;
	if (digt > 0 && !(puff->n & FLAG_PLUS) && (puff->n & FLAG_SPACE))
		ft_putchar(' ');
	((puff->n & FLAG_PRS) && (puff->precision < 1)) ? 0 : len++;
	puff->len += len + tmp;
	ft_print_space(puff->width - tmp - len, symb, puff);
	(digt < 0 && !(puff->n & FLAG_0)) ? ft_putchar('-') : 0;
	if (digt >= 0 && (puff->n & FLAG_PLUS) && !(puff->n & FLAG_0))
		ft_putchar('+');
}

static double		ft_crt_num(double num, t_print *puff, ssize_t i)
{
	if (puff->n & FLAG_PRS)
	{
		if (puff->precision > 6 && puff->precision < 19)
		{
			while (i < (18 - puff->precision))
			{
				num /= 10;
				i++;
			}
		}
		else if (puff->precision < 7)
		{
			num /= 1000000000000;
			while (i < (6 - puff->precision))
			{
				num /= 10;
				i++;
			}
		}
	}
	else
		num /= 1000000000000;
	return (num);
}

static void			ft_after_dot(double num, t_print *puff, int tmp, ssize_t i)
{
	ssize_t			a;
	ssize_t			b;
	int				len_zero;

	len_zero = 6;
	num = ft_crt_num(num, puff, 0);
	(puff->precision > 18) ? (tmp = puff->precision - 18) : 0;
	a = num;
	b = a;
	while (b != 0)
	{
		b /= 10;
		i++;
	}
	num = num * 10;
	b = num;
	(a == 0) ? i++ : 0;
	b = b % 10;
	if (b > 4)
		a += 1;
	(puff->n & FLAG_PRS) ? (len_zero = puff->precision) : 0;
	(puff->n & FLAG_PRS && puff->precision > 18) ? (len_zero = 18) : 0;
	ft_print_space(len_zero - i, '0', puff);
	ft_putnbr(a);
	ft_print_space(tmp, '0', puff);
}

void				ft_float(t_print *puff)
{
	double			u;
	ssize_t			digt;
	double			num;
	ssize_t			a;

	u = (double)va_arg(puff->ap, double);
	digt = u;
	num = u - digt;
	ft_prnt_s(digt, puff, 6, ' ');
	digt = ABS(digt);
	if (puff->n & FLAG_PRS && puff->precision < 1)
	{
		a = ABS(num * 10);
		(a > 4) ? digt++ : 0;
	}
	ft_putnbr(digt);
	if (puff->n & FLAG_PRS && puff->precision < 1)
		return ;
	ft_putchar('.');
	num = ABS(num * 1000000000000000000);
	ft_after_dot(num, puff, 0, 0);
}
