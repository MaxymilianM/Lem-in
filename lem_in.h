/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:28:35 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/13 14:28:37 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libprintf/ft_printf.h"

# define START 1
# define END 0

# define OPEN 0
# define CLOSE 1

# define GRAY 0
# define WHITE 1
# define BLACK 2

typedef struct s_table	t_able;

typedef struct		s_links
{
	t_able			*name_room;
	int				door;
	int				count_ants;

	struct s_links	*next;
	struct s_links	*prev;
}					t_links;

typedef struct		s_ways
{
	int				sum;

	t_links			*way;
	struct s_ways	*next;
}					t_ways;

struct				s_table
{
	int				n;
	int				count_ants;
	int				weight;
	int				door;
	int				color;
	char			*name;

	struct s_table	*next;
	struct s_links	*right;
};

typedef struct		s_lem
{
	int				start;
	int				end;
	int				ants;
	int				l;
	int				w;
	int				num_rooms;
	t_list			*head_t;
	t_links			*way;
	t_ways			*all_ways;
	t_able			*adj_matrix;
}					t_lem;

void				ft_reader(t_lem *in);
void				ft_builder(t_lem *in);
void				ft_finish_build(t_lem *in);
void				ft_queue(t_lem *in);
void				ft_other_ways(t_lem *in);
void				ft_ants(t_lem *in);

void				ft_clean(char **str);
int					ft_find_links(char *s);
void				ft_close_doors(t_links *queue, t_lem *in);
void				ft_error_exit(t_lem *in, int u);
void				ft_ck_room_names(t_lem *in, t_list *list);
void				ft_ck_end(t_lem *in, t_list *list);
void				ft_ck_start(t_lem *in, t_list *list);
void				ft_ck_links(t_lem *in, t_list *list);
t_links				*ft_queue_crt(t_able *start);
void				ft_clean_bad_queue(t_links *queue);
t_list				*ft_find_first_room(t_lem *in);
void				ft_dell_room(t_able **head, t_able *current, t_lem *in);
void				ft_close_end(t_lem *in);
void				ft_print_all_text(t_lem *in);

char				*ft_color_use(int i);
void				ft_print_bonus_ways(t_lem *in);

#endif
