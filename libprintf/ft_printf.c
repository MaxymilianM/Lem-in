/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:00:44 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/09 13:00:47 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_print		puff;
	va_list		ap;

	va_start(ap, format);
	va_copy(puff.ap, ap);
	puff.form = (char *)format;
	puff.len = 0;
	while (*puff.form)
	{
		puff.n = 0;
		if (*puff.form == '%' && *(puff.form + 1))
		{
			puff.form++;
			puff.form = puff.form + ft_parsing(&puff);
		}
		else if (*puff.form != '%')
		{
			write(1, puff.form, 1);
			puff.len++;
		}
		puff.form++;
	}
	va_end(puff.ap);
	va_end(ap);
	return (puff.len);
}
