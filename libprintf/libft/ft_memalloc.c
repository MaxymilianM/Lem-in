/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:01:40 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/12 14:34:31 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*rez;

	rez = (void *)malloc(size);
	if (rez == NULL)
		return (NULL);
	ft_bzero(rez, size);
	return (rez);
}
