/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:02:46 by kiborroq          #+#    #+#             */
/*   Updated: 2020/11/18 10:26:48 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_chrtostr(char c)
{
	char *str;

	if (!(str = ft_calloc(2, sizeof(char))))
		return (0);
	str[0] = c;
	return (str);
}

char	*add_precision(char *num, int n)
{
	int		len;
	int		minus;
	int		digs;
	char	*buf;

	len = ft_strlen(num);
	minus = 0;
	if (num[0] == '-')
		minus = 1;
	digs = len - minus;
	if (n < digs)
		n = digs;
	if (!(buf = ft_calloc(n + minus + 1, sizeof(char))))
	{
		free(num);
		return (0);
	}
	buf[0] = '-';
	ft_memset(buf + minus, '0', n - digs);
	ft_memcpy(buf + minus + n - digs, num + minus, digs);
	free(num);
	return (buf);
}

size_t	ft_max(int n, ...)
{
	va_list	args;
	int		max;
	int		cur;

	va_start(args, n);
	max = 0;
	while (n-- > 0)
	{
		cur = va_arg(args, int);
		if (cur > max)
			max = cur;
	}
	va_end(args);
	return (max);
}

void	ft_putnchar_fd(char c, int n, int fd)
{
	while (n-- > 0)
		ft_putchar_fd(c, fd);
}

void	putvalue(char *value, t_conv *conv)
{
	if (conv->type == 'c')
		ft_putchar_fd(value[0], 1);
	else
		ft_putstr_fd(value, 1);
}
