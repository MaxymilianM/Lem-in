/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:52:18 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/22 18:52:19 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_space_9(t_print *puff, int len)
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

void			ft_binary_print(t_print *puff)
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
		t /= 2;
		len++;
	}
	ft_count_space_9(puff, len);
	str = ft_itoa_base(a, 2, 65);
	ft_putstr(str);
	free(str);
	(puff->n & FLAG_MINUS) ? ft_count_space_after(puff, len) : 0;
	puff->len += len;
}
