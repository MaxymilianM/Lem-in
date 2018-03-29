/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_queues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:49:47 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/24 18:49:48 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_able		*ft_find_room_2(t_able *start)
{
	t_links			*finder;
	t_able			*be_find;

	finder = start->right;
	be_find = NULL;
	if (finder->name_room->n == END)
		return (finder->name_room);
	while (finder)
	{
		if (finder->name_room->door == OPEN && finder->name_room->n != START)
		{
			if (be_find == NULL)
				be_find = finder->name_room;
			else if (be_find->weight >= finder->name_room->weight)
				be_find = finder->name_room;
		}
		if (be_find && be_find->n == END)
			break ;
		finder = finder->next;
	}
	return (be_find);
}

static int			ft_find_direct(t_able *start)
{
	t_links			*find;

	find = start->right;
	while (find)
	{
		if (find->name_room->n == END)
			return (0);
		find = find->next;
	}
	return (1);
}

void				ft_help_queue(t_links *queue_last, t_able *finder)
{
	queue_last->door = CLOSE;
	queue_last->count_ants = 0;
	queue_last->next = NULL;
	queue_last->name_room = finder;
}

static void			ft_find_other_ways(t_lem *in, int i, t_able *finder)
{
	t_able			*start;
	t_links			*queue;
	t_links			*queue_last;

	start = in->adj_matrix;
	while (start && (start->n != START))
		start = start->next;
	if (ft_find_direct(start) == 0)
		return ;
	queue = ft_queue_crt(in->adj_matrix);
	queue_last = queue;
	while (queue_last->name_room->n != END && i++ < in->num_rooms)
	{
		if ((finder = ft_find_room_2(start)) == NULL)
			break ;
		queue_last->next = (t_links*)malloc(sizeof(t_links));
		queue_last->next->prev = queue_last;
		queue_last = queue_last->next;
		ft_help_queue(queue_last, finder);
		start = finder;
	}
	if (queue_last->name_room->n == END)
		ft_close_doors(queue, in);
	else
		ft_clean_bad_queue(queue);
}

void				ft_other_ways(t_lem *in)
{
	t_ways			*ways;

	ways = (t_ways *)malloc(sizeof(t_ways));
	ways->next = NULL;
	ways->way = in->way;
	in->all_ways = ways;
	ways->sum = 0;
	while (in->way != NULL)
	{
		in->way = NULL;
		ft_find_other_ways(in, 0, NULL);
		if (in->way != NULL)
		{
			ways->next = (t_ways *)malloc(sizeof(t_ways));
			ways = ways->next;
			ways->way = in->way;
			ways->sum = 0;
		}
	}
	ways->next = NULL;
}
