/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:00:35 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/18 10:31:56 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "../libft/libft.h"

# define TYPES "cspdiuxX%"
# define UNPRECISION_TYPES "csp%"
# define FLAGS "-0"
# define X_BASE "0123456789abcdef"
# define XX_BASE "0123456789ABCDEF"

typedef struct	s_conv
{
	int			minus;
	int			zero;
	int			dote;
	char		type;
	int			width;
	int			precision;
	int			value_len;
	char		*curr_pos;
	int			writed;
}				t_conv;

/*
**Main function - ft_printf.c
*/

int				ft_printf(const char *format, ...);

/*
**Function for conversion parse - parse_conv_utils.c
*/

int				get_flags(char *format, int i, t_conv *conv);
int				get_width(char *format, va_list *args, int i, t_conv *conv);
int				get_precis(char *format, va_list *args, int i, t_conv *conv);
int				get_type(char *format, int i, t_conv *conv);
t_conv			*init_conv(void);

/*
**Functions for conversion treating
*/

char			*treat_char(t_conv *conv, va_list *args);
char			*treat_str(t_conv *conv, va_list *args);
char			*treat_int(t_conv *conv, va_list *args);
char			*treat_uint(t_conv *conv, va_list *args);
char			*treat_hex(t_conv *conv, va_list *args);
char			*treat_point(t_conv *conv, va_list *args);
char			*treat_perc(t_conv *conv);

/*
**Functions for support to ft_printf work - ft_printf_utils.c
*/

void			ft_putnchar_fd(char c, int n, int fd);
size_t			ft_max(int n, ...);
char			*ft_chrtostr(char c);
char			*add_precision(char *num, int n);
void			putvalue(char *value, t_conv *conv);

#endif
