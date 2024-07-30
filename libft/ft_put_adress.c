/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:01:35 by krs               #+#    #+#             */
/*   Updated: 2024/04/14 19:58:00 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_helper(unsigned long n, const char *base)
{
	int	length;
	int	result;

	length = 0;
	if (n > (ft_strlen(base) - 1))
	{
		result = print_helper(n / ft_strlen(base), base);
		if (result < 0)
			return (-1);
		length += result;
	}
	result = ft_putchar(*(base + (n % ft_strlen(base))));
	if (result < 0)
		return (-1);
	length += result;
	return (length);
}

int	ft_put_adress(void *format)
{
	unsigned long	n;
	const char		*base;
	int				length;
	int				result;

	n = (unsigned long)format;
	base = "0123456789abcdef";
	result = ft_putstr("0x");
	if (result < 0)
		return (-1);
	length = result;
	result = print_helper(n, base);
	if (result < 0)
		return (-1);
	length += result;
	return (length);
}
