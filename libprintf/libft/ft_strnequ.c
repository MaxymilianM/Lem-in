/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:26:11 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/06 16:26:12 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	u;

	if (s1 == NULL || s2 == NULL)
		return (0);
	u = ft_strncmp(s1, s2, n);
	if (u == 0)
		return (1);
	else
		return (0);
}
