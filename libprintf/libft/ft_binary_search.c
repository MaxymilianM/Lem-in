/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:17:23 by mminenko          #+#    #+#             */
/*   Updated: 2017/11/14 15:17:25 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_binary_search(int searched, int *mass, int len)
{
	int low;
	int high;
	int middle;

	if (mass == NULL)
		return (0);
	ft_bubble_sort_num(mass, len);
	low = 0;
	high = len - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (searched < mass[middle])
			high = middle - 1;
		else if (searched > mass[middle])
			low = middle + 1;
		else
			return (1);
	}
	return (0);
}
