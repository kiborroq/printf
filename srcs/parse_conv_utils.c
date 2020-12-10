/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:11:23 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/17 16:12:20 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_flags(char *format, int i, t_conv *conv)
{
	while (format[i] && ft_strchr(FLAGS, format[i]))
	{
		if (format[i] == '0')
			conv->zero = 1;
		if (format[i] == '-')
			conv->minus = 1;
		i++;
	}
	return (i);
}

int		get_width(char *format, va_list *args, int i, t_conv *conv)
{
	if (format[i] == '*')
	{
		if ((conv->width = va_arg(*args, int)) < 0)
		{
			conv->width *= -1;
			conv->minus = 1;
		}
	}
	else
		conv->width = ft_atoi(format + i);
	while (format[i] == '*' || ft_isdigit(format[i]))
		i++;
	return (i);
}

int		get_precis(char *format, va_list *args, int i, t_conv *conv)
{
	if (format[i] != '.')
		return (i);
	conv->dote = 1;
	i++;
	if (format[i] == '*')
		conv->precision = va_arg(*args, int);
	else
		conv->precision = ft_atoi(format + i);
	if (conv->precision < 0)
	{
		conv->dote = 0;
		conv->precision = 0;
	}
	while (format[i] == '*' || ft_isdigit(format[i]))
		i++;
	return (i);
}

int		get_type(char *format, int i, t_conv *conv)
{
	char *ch;

	if (format[i] && (ch = ft_strchr(TYPES, format[i])))
	{
		conv->type = *ch;
		if (conv->dote && !ft_strchr(UNPRECISION_TYPES, conv->type))
			conv->zero = 0;
		i++;
	}
	return (i);
}

t_conv	*init_conv(void)
{
	t_conv	*new;

	if (!(new = (t_conv *)malloc(sizeof(t_conv))))
		return (0);
	new->type = 0;
	new->minus = 0;
	new->zero = 0;
	new->dote = 0;
	new->precision = 0;
	new->width = 0;
	new->value_len = 0;
	new->curr_pos = 0;
	new->writed = 0;
	return (new);
}
