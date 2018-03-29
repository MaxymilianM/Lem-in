/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:33:39 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/13 14:33:41 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			del(void *s, size_t len)
{
	len = 0;
	free(s);
}

static void		ft_clean_all_2(t_lem *in)
{
	t_links		*tmp;
	t_able		*dell;

	while (in->adj_matrix)
	{
		while (in->adj_matrix->right)
		{
			tmp = in->adj_matrix->right;
			in->adj_matrix->right = in->adj_matrix->right->next;
			free(tmp);
		}
		dell = in->adj_matrix;
		in->adj_matrix = in->adj_matrix->next;
		free(dell->name);
		free(dell);
	}
}

static void		ft_clean_all(t_lem *in)
{
	t_links		*tmp;
	t_ways		*to_dell;

	ft_lstdel((&in->head_t), del);
	while (in->all_ways)
	{
		to_dell = in->all_ways;
		while (to_dell->way)
		{
			tmp = to_dell->way;
			to_dell->way = to_dell->way->next;
			free(tmp);
		}
		in->all_ways = in->all_ways->next;
		free(to_dell);
	}
	ft_clean_all_2(in);
}

void			ft_error_exit(t_lem *in, int u)
{
	ft_clean_all(in);
	if (u == 1)
		ft_printf("ERROR. Name of room is incorrect.\n");
	else if (u == 3)
		ft_printf("ERROR. START or END haven't links with other rooms.\n");
	else if (u == 4)
		ft_printf("ERROR. Not valid file.\n");
	else if (u == 5)
		ft_printf("ERROR. Rooms have bad links.\n");
	else if (u == 6)
		ft_printf("ERROR. Link with undeclared room.\n");
	else if (u == 7)
		ft_printf("ERROR. No START room.\n");
	else if (u == 8)
		ft_printf("ERROR. No END room.\n");
	else if (u == 9)
		ft_printf("ERROR. Wrong links.\n");
	else if (u == 10)
		ft_printf("ERROR. Wrong START or END room.\n");
	else if (u == 11)
		ft_printf("ERROR. START or END command unexpected here.\n");
	else
		ft_printf("ERROR\n");
	(in->l == 1) ? system("leaks -quiet lem-in") : 0;
	exit(0);
}

int				main(int argc, char **argv)
{
	t_lem		in;

	in.l = 0;
	in.w = 0;
	if (argc == 2 && ft_strequ(argv[1], "-l"))
		in.l = 1;
	else if (argc == 2 && ft_strequ(argv[1], "-w"))
		in.w = 1;
	in.start = 0;
	in.end = 0;
	in.num_rooms = 0;
	in.way = NULL;
	in.all_ways = NULL;
	in.adj_matrix = NULL;
	ft_reader(&in);
	ft_builder(&in);
	ft_queue(&in);
	ft_ants(&in);
	(in.w == 1) ? ft_print_bonus_ways(&in) : 0;
	ft_clean_all(&in);
	(in.l == 1) ? system("leaks -quiet lem-in") : 0;
	return (0);
}
