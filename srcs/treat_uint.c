/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:15:44 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/17 16:15:59 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*treat_uint(t_conv *conv, va_list *args)
{
	unsigned int	num;
	char			*value;

	num = va_arg(*args, unsigned int);
	if (!num && conv->dote && !conv->precision)
	{
		if (!(value = ft_calloc(1, sizeof(char))))
			return (0);
	}
	else
	{
		if (!(value = ft_uitoa(num)))
			return (0);
		if (!(value = add_precision(value, conv->precision)))
			return (0);
	}
	conv->value_len = ft_strlen(value);
	return (value);
}
