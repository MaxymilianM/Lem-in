/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:25:52 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/08 13:25:53 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t	u;

	if (s1 == NULL || s2 == NULL)
		return (0);
	u = ft_strcmp(s1, s2);
	if (u == 0)
		return (1);
	else
		return (0);
}
