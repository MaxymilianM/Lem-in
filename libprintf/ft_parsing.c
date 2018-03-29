/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:24:17 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/09 13:24:21 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_spesific_help(t_print *puff, int i)
{
	(*(puff->form + i) == '%') ? puff->n |= SPECIFIC_PT : 0;
	(*(puff->form + i) == 'S') ? ((puff->n |= SPECIFIC_S) &&
		(puff->n |= MODIF_L)) : 0;
	(*(puff->form + i) == 'o') ? puff->n |= SPECIFIC_O : 0;
	(*(puff->form + i) == 'O') ? ((puff->n |= SPECIFIC_O) &&
		(puff->n |= MODIF_L)) : 0;
	(*(puff->form + i) == 'u') ? puff->n |= SPECIFIC_U : 0;
	(*(puff->form + i) == 'U') ? ((puff->n |= SPECIFIC_U) &&
		(puff->n |= MODIF_L)) : 0;
	(*(puff->form + i) == 'C') ? ((puff->n |= SPECIFIC_C) &&
		(puff->n |= MODIF_L)) : 0;
	(*(puff->form + i) == 'D') ? ((puff->n |= SPECIFIC_INT) &&
		(puff->n |= MODIF_L)) : 0;
	(*(puff->form + i) == 'p') ? ((puff->n |= SPECIFIC_P) &&
		(puff->n |= FLAG_SHARP) && (puff->n |= MODIF_Z)) : 0;
	(*(puff->form + i) == 'X') ? puff->n |= SPECIFIC_BX : 0;
	(*(puff->form + i) == 'x') ? puff->n |= SPECIFIC_X : 0;
	(*(puff->form + i) == 'b') ? puff->n |= SPECIFIC_B : 0;
	(*(puff->form + i) == 'n') ? puff->n |= SPECIFIC_N : 0;
	if (*(puff->form + i) == 'f' || *(puff->form + i) == 'F')
		puff->n |= SPECIFIC_F;
	(*(puff->form + i) == 'k') ? puff->n |= SPECIFIC_K : 0;
}

void				ft_spesific(t_print *puff, int i)
{
	if (*(puff->form + i) == 'c')
		puff->n |= SPECIFIC_C;
	else if (*(puff->form + i) == 's')
		puff->n |= SPECIFIC_S;
	else if (*(puff->form + i) == 'i' || *(puff->form + i) == 'd')
		puff->n |= SPECIFIC_INT;
	else
		ft_spesific_help(puff, i);
}

ssize_t				ft_format_int(t_print *puff)
{
	ssize_t			a;

	if (puff->n & MODIF_LL)
		a = (long long int)va_arg(puff->ap, long long int);
	else if (puff->n & MODIF_Z)
		a = (size_t)va_arg(puff->ap, size_t);
	else if (puff->n & MODIF_L)
		a = (long int)va_arg(puff->ap, long int);
	else if (puff->n & MODIF_HH)
		a = (char)va_arg(puff->ap, int);
	else if (puff->n & MODIF_H)
		a = (short)va_arg(puff->ap, int);
	else if (puff->n & MODIF_J)
		a = (intmax_t)va_arg(puff->ap, intmax_t);
	else
		a = (int)va_arg(puff->ap, int);
	return (a);
}

void				ft_persent(t_print *puff)
{
	char			symb;

	symb = ' ';
	puff->len++;
	(puff->n & FLAG_0) ? (symb = '0') : 0;
	if (puff->width > 0 && !(puff->n & FLAG_MINUS))
		ft_print_space(puff->width - 1, symb, puff);
	ft_putchar('%');
	if (puff->width > 0 && (puff->n & FLAG_MINUS))
		ft_print_space(puff->width - 1, symb, puff);
}

int					ft_parsing(t_print *puff)
{
	int				i;

	i = ft_flags(puff);
	ft_spesific(puff, i);
	(puff->n & SPECIFIC_S && !(puff->n & MODIF_L)) ? ft_string(puff) : 0;
	(puff->n & SPECIFIC_C) ? ft_char(puff) : 0;
	(puff->n & SPECIFIC_INT) ? ft_int(puff) : 0;
	(puff->n & SPECIFIC_PT) ? ft_persent(puff) : 0;
	(puff->n & SPECIFIC_O) ? ft_octal(puff) : 0;
	(puff->n & SPECIFIC_U) ? ft_unsign(puff) : 0;
	((puff->n & SPECIFIC_X) || (puff->n & SPECIFIC_BX) ||
		(puff->n & SPECIFIC_P)) ? ft_hex(puff) : 0;
	(puff->n & SPECIFIC_B) ? ft_binary_print(puff) : 0;
	((puff->n & SPECIFIC_S) && (puff->n & MODIF_L)) ? ft_wstring(puff, 0) : 0;
	(puff->n & SPECIFIC_N) ? ft_num_print(puff) : 0;
	(puff->n & SPECIFIC_F) ? ft_float(puff) : 0;
	(puff->n & SPECIFIC_K) ? ft_data_time(puff) : 0;
	return (i);
}
