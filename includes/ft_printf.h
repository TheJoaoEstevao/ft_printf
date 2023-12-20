/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:51:56 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/15 21:25:37 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		dot;
	int		width;
	int		pcs;
	char	type;
}	t_format;

# ifdef __linux__
#  define IS_LINUX 1
#  define OS "LINUX"
#  define S_EMPTY "(null)"
#  define S_EMPTY_L 6
#  define P_EMPTY "(nil)"
#  define P_EMPTY_L 5
# else
#  define IS_LINUX 0
#  define OS "MAC"
#  define S_EMPTY "(null)"
#  define S_EMPTY_L 6
#  define P_EMPTY "0x0"
#  define P_EMPTY_L 3
# endif

# define F_TYPE "cspdiuxX%"

int			ft_printf(const char *str, ...);
int			ft_istype(char c);
int			ft_set_format(char c, va_list ap, t_format *f);
void		ft_reset_format(t_format *f);
char		*ft_format_str(char *fstr, char c, int i);
int			ft_print_str(char *cstr, t_format *f);
char		*ft_convert_format(va_list ap, t_format *f);
char		*ft_convert_type(va_list ap, t_format *f);
char		*ft_convert_flag(char	*cstr, t_format *f);
char		*ft_convert_pcs(char *cstr, t_format *f);
char		*ft_convert_width(char	*cstr, t_format *f);
char		*ft_convert_c(char c);
char		*ft_convert_d(int d);
char		*ft_convert_s(char *s);
char		*ft_convert_p(size_t ptr);
char		*ft_convert_u(unsigned int d);
char		*ft_convert_x(unsigned int nb, int is_upper);
int			ft_percent(void);
int			ft_char_padding(int width, int minus_flag);
int			ft_char(va_list ap, t_format *f);
int			ft_pointer(va_list ap, t_format *f);
int			ft_check_null_empty(char *cstr, t_format *f);
int			ft_str_width(char *cstr, t_format *f, int str_len);

#endif
