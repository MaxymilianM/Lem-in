/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:22:07 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/27 11:22:16 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			ft_direct_print(t_lem *in)
{
	t_able			*s;
	t_able			*e;

	s = in->all_ways->way->name_room;
	e = in->all_ways->way->next->name_room;
	while (in->ants)
	{
		e->count_ants++;
		ft_printf("L%d-%s", e->count_ants, e->name);
		if ((in->ants - 1) > 0)
			ft_printf(" ");
		in->ants--;
	}
	ft_printf("\n");
}

static int			ft_print_ants(t_ways *allw, int flag, int a, int i)
{
	t_links			*link;

	while (allw)
	{
		link = allw->way;
		while (link->next)
			link = link->next;
		while (link && link->name_room->n != START)
		{
			if (flag == 1 && link->count_ants > 0)
				ft_printf(" ");
			if (link->count_ants > 0)
			{
				flag = 1;
				ft_printf("%sL%d-%s%s", ft_color_use(i), link->count_ants,
					link->name_room->name, COLOR_RESET);
				a++;
			}
			link = link->prev;
		}
		allw = allw->next;
		i++;
	}
	(a > 0) ? ft_printf("\n") : 0;
	return (a);
}

static void			ft_give_start_num(t_ways *allw, t_lem *in)
{
	t_links			*link;
	int				u;

	u = 0;
	while (allw)
	{
		link = allw->way;
		link->count_ants = in->start;
		if (in->ants > 1)
			in->start++;
		else
			in->start = -1;
		in->ants--;
		allw = allw->next;
	}
}

static void			ft_move_ants(t_ways *allw)
{
	t_links			*link;

	while (allw)
	{
		link = allw->way;
		while (link->next)
			link = link->next;
		while (link->prev)
		{
			link->count_ants = link->prev->count_ants;
			link = link->prev;
		}
		allw = allw->next;
	}
}

void				ft_ants(t_lem *in)
{
	t_ways			*allw;
	int				a;
	int				num;

	ft_close_end(in);
	ft_print_all_text(in);
	a = 1;
	allw = in->all_ways;
	in->start = 1;
	if (allw->way->next->name_room->n == END)
	{
		ft_direct_print(in);
		return ;
	}
	num = in->ants;
	while (a > 0)
	{
		ft_give_start_num(allw, in);
		ft_move_ants(allw);
		a = ft_print_ants(allw, 0, 0, 0);
	}
}
