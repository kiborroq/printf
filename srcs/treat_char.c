/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:12:38 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/17 16:12:52 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*treat_char(t_conv *conv, va_list *args)
{
	char	c;
	char	*value;

	c = va_arg(*args, int);
	if (!(value = ft_chrtostr(c)))
		return (0);
	conv->value_len = 1;
	return (value);
}
