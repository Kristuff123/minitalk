/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:21:24 by krs               #+#    #+#             */
/*   Updated: 2024/07/31 17:29:09 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <math.h>

int		ft_putchar(char c);
int		ft_put_hexadecimal(unsigned long n, char format);
int		ft_putnbr(int n);
int		ft_putstr(char const *s);
int		ft_put_unsigned(unsigned long n);
int		ft_put_adress(void *format);
int		ft_atoi(const char *str);
long	ft_absolut(long n);
void	ft_putbase_fd(int nbr, const char *base, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char const *str, int c);

#endif
