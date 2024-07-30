/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:04:39 by krs               #+#    #+#             */
/*   Updated: 2024/04/11 21:22:24 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbase_fd(int nbr, const char *base, int fd)
{
	int		base_length;
	long	number;
	char	c;

	if (!base || !*base)
		return ;
	base_length = ft_strlen(base);
	if (nbr < 0)
	{
		write(fd, "-", 1);
		number = -((long)nbr);
	}
	else
		number = (long)nbr;
	if (number > (base_length - 1))
		ft_putbase_fd(number / base_length, base, fd);
	c = *(base + (number % base_length));
	write(fd, &c, 1);
}
