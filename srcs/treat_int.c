/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:13:43 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/17 16:13:54 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*treat_int(t_conv *conv, va_list *args)
{
	int		num;
	char	*value;

	num = va_arg(*args, int);
	if (!num && conv->dote && !conv->precision)
	{
		if (!(value = ft_calloc(1, sizeof(char))))
			return (0);
	}
	else
	{
		if (!(value = ft_itoa(num)))
			return (0);
		if (!(value = add_precision(value, conv->precision)))
			return (0);
	}
	conv->value_len = ft_strlen(value);
	return (value);
}
