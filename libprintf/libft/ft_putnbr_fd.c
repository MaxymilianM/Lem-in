/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:01:37 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/08 13:01:39 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb1;

	nb1 = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb1 = n * (-1);
	}
	if (nb1 > 9)
	{
		ft_putnbr_fd(nb1 / 10, fd);
	}
	ft_putchar_fd(48 + nb1 % 10, fd);
}
