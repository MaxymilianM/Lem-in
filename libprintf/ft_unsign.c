/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:23:16 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/20 14:23:18 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_space_8(t_print *puff, int len)
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
		ft_print_space(num, symb, puff);
	}
	if (puff->precision > len)
		ft_print_space(puff->precision - len, '0', puff);
	return (0);
}

static int		ft_check_null(size_t a, t_print *puff)
{
	if (a == 0)
	{
		if ((puff->n & FLAG_PRS) || (puff->n & FLAG_0))
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

void			ft_unsign(t_print *puff)
{
	size_t		t;
	size_t		a;
	int			len;
	char		*str;

	len = 0;
	a = ft_format_hex(puff);
	t = a;
	(t == 0) ? len++ : 0;
	while (t != 0)
	{
		t /= 10;
		len++;
	}
	if (ft_check_null(a, puff) == 0)
		return ;
	ft_count_space_8(puff, len);
	str = ft_itoa_base(a, 10, 65);
	ft_putstr(str);
	free(str);
	(puff->n & FLAG_MINUS) ? ft_count_space_after(puff, len) : 0;
	puff->len += len;
}
