/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:16:41 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/17 16:28:32 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin_wrap(char *pref, char *value)
{
	char	*new;

	if (!(new = ft_strjoin(pref, value)))
	{
		free(value);
		return (0);
	}
	free(value);
	return (new);
}

char	*treat_point(t_conv *conv, va_list *args)
{
	unsigned long	point;
	char			*value;

	point = va_arg(*args, unsigned long);
	if (!point && conv->dote && !conv->precision)
	{
		if (!(value = ft_calloc(1, sizeof(char))))
			return (0);
	}
	else
	{
		if (!(value = ft_itoa_base(point, X_BASE)))
			return (0);
		if (!(value = add_precision(value, conv->precision)))
			return (0);
	}
	if (!(value = ft_strjoin_wrap("0x", value)))
		return (0);
	conv->value_len = ft_strlen(value);
	return (value);
}
