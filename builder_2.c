/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:27:24 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/24 18:27:27 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_links		*ft_new_matrix_node(char *list, char *name, t_lem *in)
{
	t_links			*new_node;
	char			**names_r;
	char			*str;
	t_able			*tmp;

	tmp = in->adj_matrix;
	new_node = (t_links *)malloc(sizeof(t_links));
	names_r = ft_strsplit(list, '-');
	if (ft_strequ(names_r[0], name))
		str = names_r[1];
	else
		str = names_r[0];
	new_node->name_room = NULL;
	while (tmp)
	{
		if (ft_strequ(tmp->name, str))
		{
			new_node->name_room = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	ft_clean(names_r);
	new_node->next = NULL;
	return (new_node);
}

static int			ft_check_valid_room(char *s1, char *s2, t_lem *in)
{
	t_able			*tmp;
	int				flag_1;
	int				flag_2;

	tmp = in->adj_matrix;
	flag_2 = 0;
	flag_1 = 0;
	while (tmp)
	{
		if (ft_strequ(s2, tmp->name))
			flag_1 = 1;
		if (ft_strequ(s1, tmp->name))
			flag_2 = 1;
		tmp = tmp->next;
	}
	if ((flag_1 + flag_2) == 2)
		return (1);
	return (0);
}

static int			ft_name_eq(char *s1, char *s2, t_lem *in)
{
	char			**names_r;

	names_r = ft_strsplit(s1, '-');
	if (ft_check_valid_room(names_r[0], names_r[1], in) == 0)
	{
		ft_clean(names_r);
		ft_error_exit(in, 6);
	}
	if (ft_strequ(s2, names_r[0]) || ft_strequ(s2, names_r[1]))
	{
		if (ft_strequ(names_r[1], names_r[0]))
		{
			ft_clean(names_r);
			return (0);
		}
		ft_clean(names_r);
		return (1);
	}
	ft_clean(names_r);
	return (0);
}

static t_links		*ft_build_links(char *name, t_list *list, t_lem *in)
{
	t_links			*first;
	t_links			*help;

	first = NULL;
	while (list)
	{
		if (ft_find_links(list->content) && ft_name_eq(list->content, name, in))
		{
			if (first == NULL)
			{
				help = ft_new_matrix_node(list->content, name, in);
				first = help;
			}
			else
			{
				help->next = ft_new_matrix_node(list->content, name, in);
				help = help->next;
			}
		}
		list = list->next;
	}
	return (first);
}

void				ft_finish_build(t_lem *in)
{
	t_able			*tmp;
	t_list			*list;

	list = in->head_t;
	tmp = in->adj_matrix;
	while (tmp)
	{
		tmp->right = ft_build_links(tmp->name, in->head_t, in);
		(tmp->right == NULL) ? ft_dell_room(&in->adj_matrix, tmp, in) : 0;
		tmp = tmp->next;
	}
}
