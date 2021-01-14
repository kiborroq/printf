/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:20:22 by kiborroq          #+#    #+#             */
/*   Updated: 2021/01/14 09:20:22 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int ch)
{
	if (ch == 32 || (ch > 8 && ch < 14))
		return (1);
	return (0);
}
