/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:09:26 by krs               #+#    #+#             */
/*   Updated: 2024/04/14 20:19:40 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numbers_length(long n)
{
	int	i;

	if (n < 0)
	{
		n = ft_absolut(n);
		i = 1;
	}
	else
		i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int	ft_putnbr(int n)
{
	int			nbr_length;
	char const	*base;

	base = "0123456789";
	nbr_length = numbers_length(n);
	ft_putbase_fd(n, base, 1);
	return (nbr_length);
}
