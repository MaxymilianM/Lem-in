/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:38:03 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/25 15:38:04 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>

void			ft_data_time(t_print *puff)
{
	time_t		t;
	struct tm	*tm;
	char		s[64];

	t = time(NULL);
	tm = localtime(&t);
	strftime(s, sizeof(s), "%c", tm);
	ft_putstr(s);
	puff->len += ft_strlen(s);
}
