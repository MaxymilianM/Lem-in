/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:33:51 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/13 14:33:54 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			ft_check_error(char *line, t_lem *in, int *f_a, int *s_e)
{
	int				u;

	u = 0;
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			(ft_strequ(line, "##start")) ? (s_e[0] = 1) : 0;
			(ft_strequ(line, "##end")) ? (s_e[1] = 1) : 0;
		}
	}
	else if (*f_a == 0)
	{
		if (s_e[0] == 1 || s_e[1] == 1)
			return (-1);
		*f_a = 1;
		while (ft_isdigit(line[u]))
			u++;
		if (line[u] != '\0' || u > 8 || ((in->ants = ft_atoi(line)) < 1))
			return (-1);
	}
	else if (line[0] == 'L')
		return (-1);
	return (0);
}

static void			ft_all_text(char *line, t_lem *in, t_list **all_text)
{
	t_list			*tmp;

	if (*all_text == NULL)
	{
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		(*all_text) = tmp;
		in->head_t = (*all_text);
	}
	else
	{
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		(*all_text)->next = tmp;
		(*all_text) = (*all_text)->next;
	}
}

void				ft_reader(t_lem *in)
{
	int				ret;
	char			*line;
	t_list			*all_text;
	int				find_ants;
	int				s_e[2];

	all_text = NULL;
	find_ants = 0;
	s_e[0] = 0;
	s_e[1] = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_check_error(line, in, &find_ants, s_e) == -1)
			ft_error_exit(in, 2);
		ft_all_text(line, in, &all_text);
		free(line);
	}
	(ret == -1) ? ft_error_exit(in, 4) : 0;
	(s_e[0] == 0) ? ft_error_exit(in, 7) : 0;
	(s_e[1] == 0) ? ft_error_exit(in, 8) : 0;
	ft_ck_links(in, in->head_t);
	ft_ck_start(in, in->head_t);
	ft_ck_end(in, in->head_t);
	ft_ck_room_names(in, in->head_t);
}
