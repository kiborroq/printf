/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:03:35 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/18 10:26:29 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*treat_conv(t_conv *conv, va_list *args)
{
	char type;
	char *value;

	type = conv->type;
	value = 0;
	if (type == 'c')
		value = treat_char(conv, args);
	else if (type == 's')
		value = treat_str(conv, args);
	else if (type == 'i' || type == 'd')
		value = treat_int(conv, args);
	else if (type == 'p')
		value = treat_point(conv, args);
	else if (type == 'u')
		value = treat_uint(conv, args);
	else if (type == 'x' || type == 'X')
		value = treat_hex(conv, args);
	else if (type == '%')
		value = treat_perc(conv);
	if (!value)
		return (0);
	return (value);
}

static t_conv	*parse_conv(char *format, va_list *args)
{
	t_conv	*conv;
	int		i;

	if (!(conv = init_conv()))
		return (0);
	i = 1;
	i = get_flags(format, i, conv);
	i = get_width(format, args, i, conv);
	i = get_precis(format, args, i, conv);
	i = get_type(format, i, conv);
	conv->curr_pos = format + i;
	return (conv);
}

static void		print_value(t_conv *conv, char *value)
{
	if (conv->minus == 1)
	{
		putvalue(value, conv);
		ft_putnchar_fd(' ', conv->width - conv->value_len, 1);
	}
	else if (conv->zero == 1)
	{
		if (value[0] == '-' && (conv->type == 'i' || conv->type == 'd'))
		{
			ft_putchar_fd('-', 1);
			value++;
		}
		ft_putnchar_fd('0', conv->width - conv->value_len, 1);
		putvalue(value, conv);
	}
	else
	{
		ft_putnchar_fd(' ', conv->width - conv->value_len, 1);
		putvalue(value, conv);
	}
	conv->writed = ft_max(2, conv->width, conv->value_len);
}

static t_conv	*print_conv(char *format, va_list *args)
{
	t_conv	*conv;
	char	*value;

	if (!(conv = parse_conv(format, args)))
		return (0);
	if (conv->type == 0)
		return (conv);
	if (!(value = treat_conv(conv, args)))
	{
		free(conv);
		return (0);
	}
	print_value(conv, value);
	free(value);
	return (conv);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	t_conv	*conv;
	int		writed;

	writed = 0;
	va_start(args, format);
	while (*format)
		if (*format == '%')
		{
			if (!(conv = print_conv((char *)format, &args)))
				return (writed);
			writed += conv->writed;
			format = conv->curr_pos;
			free(conv);
		}
		else
		{
			write(1, format, 1);
			writed++;
			format++;
		}
	va_end(args);
	return (writed);
}
