/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:14:17 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/17 16:14:27 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*treat_perc(t_conv *conv)
{
	char	*value;

	if (!(value = ft_chrtostr('%')))
		return (0);
	conv->value_len = 1;
	return (value);
}
