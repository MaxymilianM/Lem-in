/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:33:25 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/09 16:33:26 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_space(int len, char symb, t_print *puff)
{
	(len > 0) ? puff->len += len : 0;
	while (len > 0)
	{
		ft_putchar(symb);
		len--;
	}
}

void		ft_num_print(t_print *puff)
{
	int		*num;

	num = va_arg(puff->ap, int*);
	*num = puff->len;
}

static void	ft_field_width(char *start, char *finish, t_print *puff)
{
	int		i;

	i = 0;
	while (start + i < finish)
	{
		if (ft_isdigit(*(start + i)) && *(start + i - 1) != '.'
			&& *(start + i) != '0')
		{
			puff->width = ABS(ft_atoi(start + i));
			break ;
		}
		i++;
	}
}

static void	ft_check_flag(char *start, char *finish, t_print *puff)
{
	puff->width = 0;
	ft_field_width(start, finish, puff);
	while (start < finish)
	{
		if (*start == '.')
		{
			puff->n |= FLAG_PRS;
			start++;
			puff->precision = ABS(ft_atoi(start));
		}
		(*start == 'l') ? puff->n |= MODIF_L : 0;
		(*start == 'h') ? puff->n |= MODIF_H : 0;
		(*start == 'j') ? puff->n |= MODIF_J : 0;
		(*start == '+') ? puff->n |= FLAG_PLUS : 0;
		(*start == '-') ? puff->n |= FLAG_MINUS : 0;
		(*start == ' ') ? puff->n |= FLAG_SPACE : 0;
		(*start == '#') ? puff->n |= FLAG_SHARP : 0;
		(*start == 'z') ? puff->n |= MODIF_Z : 0;
		(*start == 'h' && *(start + 1) == 'h') ? puff->n |= MODIF_HH : 0;
		(*start == 'l' && *(start + 1) == 'l') ? puff->n |= MODIF_LL : 0;
		(*start == '0' && *(start - 1) != '.'
			&& !(ft_isdigit(*(start - 1)))) ? puff->n |= FLAG_0 : 0;
		start++;
	}
}

int			ft_flags(t_print *puff)
{
	char	*str;
	char	s2[20];
	char	s3[40];
	int		i;

	i = 0;
	ft_strcpy(s2, "sSpdDioOuUxXcCbnfFk");
	ft_strcpy(s3, " %.+-#0123456789hljzsSpdDioOuUxXcCbnfFk");
	str = puff->form;
	while (*str && *str != '%')
	{
		if (ft_strchr(s2, *str))
			break ;
		else if (!(ft_strchr(s3, *str)))
		{
			write(1, str, 1);
			puff->len++;
			break ;
		}
		str++;
		i++;
	}
	puff->precision = 0;
	ft_check_flag(puff->form, str, puff);
	return (i);
}
