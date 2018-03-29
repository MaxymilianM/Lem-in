/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:53:49 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/27 12:53:51 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char				*ft_color_use(int i)
{
	if (i == 0)
		return (COLOR_RESET);
	else if (i == 1)
		return (COLOR_RED);
	else if (i == 2)
		return (COLOR_GREEN);
	else if (i == 3)
		return (COLOR_CYAN);
	else if (i == 4)
		return (COLOR_YELLOW);
	else if (i == 5)
		return (COLOR_MAGENTA);
	else if (i == 6)
		return (COLOR_BLUE);
	else
		return (COLOR_RESET);
}

void				ft_print_bonus_ways(t_lem *in)
{
	t_ways			*allw;
	t_links			*link;
	char			*color;
	int				i;

	i = 0;
	allw = in->all_ways;
	ft_printf("\nAll ways:\n");
	while (allw)
	{
		link = allw->way;
		while (link)
		{
			color = ft_color_use(i);
			ft_printf("%s(%s)%s", color, link->name_room->name, COLOR_RESET);
			if (link->next)
				ft_printf("%s->%s", color, COLOR_RESET);
			link = link->next;
		}
		ft_printf("\n");
		i++;
		allw = allw->next;
	}
}
