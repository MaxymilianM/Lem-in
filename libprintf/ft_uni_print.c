/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:00:48 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/13 18:00:50 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_byte_str(wchar_t *s)
{
	int				size;

	size = 0;
	while (*s)
	{
		size += ft_byte_s(*s);
		s++;
	}
	return (size);
}

static int			ft_help_print(t_print *puff, wchar_t *s2, int num)
{
	int				tmp;
	int				b_s;
	int				len_tmp;

	tmp = puff->precision;
	len_tmp = 0;
	while (*s2 && tmp > 0)
	{
		b_s = ft_byte_s(*s2);
		(tmp >= b_s) ? len_tmp += b_s : 0;
		tmp -= b_s;
		s2++;
	}
	num = puff->width - len_tmp;
	return (num);
}

static void			ft_str_space_2(t_print *puff, int len, wchar_t *s2, int num)
{
	char			symb;

	symb = ' ';
	(puff->n & FLAG_0) ? (symb = '0') : 0;
	if (puff->precision > 0)
	{
		if (puff->precision < len)
			num = ft_help_print(puff, s2, num);
		else
			num = ABS(puff->width - len);
	}
	else if (puff->width > len)
		num = puff->width - len;
	else if (puff->n & FLAG_PRS)
		num = puff->width;
	ft_print_space(num, symb, puff);
}

static void			ft_help_wstr(int tmp, wchar_t *s, t_print *puff)
{
	int				s_byte;

	while (*s && tmp > 0)
	{
		s_byte = ft_byte_s(*s);
		if (tmp >= s_byte)
		{
			ft_unicode(*s);
			puff->len += s_byte;
		}
		tmp -= s_byte;
		s++;
	}
}

void				ft_wstring(t_print *puff, int len)
{
	wchar_t			*s;
	wchar_t			*s2;
	int				tmp;
	int				len_s;

	if ((s = va_arg(puff->ap, wchar_t*)) == NULL)
	{
		ft_putstr("(null)");
		puff->len += 6;
		return ;
	}
	len = 0;
	while (s[len])
		len++;
	len_s = ft_byte_str(s);
	s2 = s;
	(puff->n & FLAG_PRS) ? (tmp = puff->precision) :
		(tmp = len_s);
	if (puff->width > 0 && !(puff->n & FLAG_MINUS))
		ft_str_space_2(puff, len_s, s2, 0);
	ft_help_wstr(tmp, s, puff);
	if (puff->width > 0 && (puff->n & FLAG_MINUS))
		ft_str_space_2(puff, len_s, s2, 0);
}
