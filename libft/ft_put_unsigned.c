/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:13:22 by krs               #+#    #+#             */
/*   Updated: 2024/04/14 20:12:20 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned(unsigned long n)
{
	int				length;
	char			*base;
	unsigned long	base_length;

	base = "0123456789";
	base_length = ft_strlen(base);
	length = 0;
	if (n > (base_length - 1))
		length += ft_put_unsigned(n / base_length);
	length += ft_putchar(*(base + (n % base_length)));
	return (length);
}
