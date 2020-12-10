/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:38:10 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/03 15:02:51 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new_s;
	unsigned int	i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	i = 0;
	while (i < len)
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
