/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:41:52 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/14 14:41:54 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort_num(int *values, int n)
{
	int i;
	int temp;
	int u;

	if (values == NULL)
		return ;
	u = 0;
	while (u < n)
	{
		i = 0;
		while (i < (n - 1))
		{
			if (values[i] > values[i + 1])
			{
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
			}
			i++;
		}
		u++;
	}
}
