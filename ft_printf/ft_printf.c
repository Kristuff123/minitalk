/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:02:48 by kgraczyk          #+#    #+#             */
/*   Updated: 2024/08/02 18:07:29 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

static int	ft_formatter(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr((va_arg(args, int))));
	else if (format == 'X' || format == 'x')
		return (ft_put_hexadecimal(va_arg(args, unsigned int), format));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_put_adress(ptr));
		return (ft_putstr("0x0"));
	}
	else if (format == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

static int	ft_f_processor(const char *str, int *i, va_list args, int *length)
{
	int		format_result;
	char	next_char;

	next_char = *(str + *i + 1);
	if (*(str + *i) == '%' && next_char && ft_strchr("cspdiuxX%", next_char))
	{
		format_result = ft_formatter(args, next_char);
		if (format_result < 0)
			return (-1);
		*length += format_result;
		(*i)++;
	}
	else
		*length += ft_putchar(*(str + *i));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (ft_f_processor(str, &i, args, &length) < 0)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (length);
}
