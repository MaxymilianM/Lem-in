/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:00:50 by mminenko          #+#    #+#             */
/*   Updated: 2018/02/09 13:00:52 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

# define ABS(Value) Value < 0 ? -Value : Value

# define SPECIFIC_C 1 << 0
# define SPECIFIC_S 1 << 1
# define SPECIFIC_INT 1 << 2
# define SPECIFIC_PT 1 << 3
# define SPECIFIC_O 1 << 4
# define SPECIFIC_U 1 << 5
# define SPECIFIC_X 1 << 6
# define SPECIFIC_BX 1 << 7
# define SPECIFIC_P 1 << 8

# define MODIF_L 1 << 9
# define MODIF_H 1 << 10
# define MODIF_HH 1 << 11
# define MODIF_LL 1 << 12
# define MODIF_Z 1 << 13
# define MODIF_J 1 << 14

# define FLAG_0 1 << 15
# define FLAG_PLUS 1 << 16
# define FLAG_MINUS 1 << 17
# define FLAG_SPACE 1 << 18
# define FLAG_PRS 1 << 19
# define FLAG_SHARP 1 << 20

# define SPECIFIC_B 1 << 21
# define SPECIFIC_N 1 << 22
# define SPECIFIC_F 1 << 23
# define SPECIFIC_K 1 << 24

# define COLOR_RESET   "\x1b[0m"
# define BOLD_FONT     "\x1b[1m"
# define UNDERLINING   "\x1b[4m"
# define COLOR_BLACK   "\x1b[30m"
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"

# define FON_BLACK   "\x1b[40m"
# define FON_RED     "\x1b[41m"
# define FON_GREEN   "\x1b[42m"
# define FON_YELLOW  "\x1b[43m"
# define FON_BLUE    "\x1b[44m"
# define FON_MAGENTA "\x1b[45m"
# define FON_CYAN    "\x1b[46m"

typedef struct	s_print
{
	int			n;
	int			len;
	int			width;
	int			precision;
	char		*form;
	va_list		ap;
}				t_print;

int				ft_printf(const char *form, ...);
int				ft_parsing(t_print *puff);
char			*ft_itoa_base(size_t n, int base, int registr);
int				ft_flags(t_print *puff);
void			ft_print_space(int len, char symb, t_print *puff);
void			ft_unicode(unsigned int symbol);
void			ft_string(t_print *puff);
void			ft_char(t_print *puff);
int				ft_size_bin(wchar_t value);
void			ft_int(t_print *puff);
void			ft_wstring(t_print *puff, int len);
void			ft_wchar(t_print *puff);
void			ft_hex(t_print *puff);
size_t			ft_format_hex(t_print *puff);
ssize_t			ft_format_int(t_print *puff);
int				ft_count_space_after(t_print *puff, int len);
void			ft_octal(t_print *puff);
void			ft_unsign(t_print *puff);
void			ft_binary_print(t_print *puff);
int				ft_byte_s(unsigned int value);
void			ft_num_print(t_print *puff);
void			ft_float(t_print *puff);
void			ft_data_time(t_print *puff);

#endif
