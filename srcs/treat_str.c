/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:14:51 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/18 12:10:10 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*treat_str(t_conv *conv, va_list *args)
{
	char *value;

	if (!(value = va_arg(*args, char *)))
		value = "(null)";
	if (!conv->dote)
	{
		if (!(value = ft_strdup(value)))
			return (0);
	}
	else if (!(value = ft_strndup(value, conv->precision)))
		return (0);
	conv->value_len = ft_strlen(value);
	return (value);
}
