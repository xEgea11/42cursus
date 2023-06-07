/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:06:48 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/25 21:58:58 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count += 1;
	return (count);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	size;

	size = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[size] != '\0')
		write(fd, &s[size++], 1);
	return (size);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		dash;
	char	modulo;
	int		size;

	size = 0;
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		size += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		dash = '-';
		size += 1;
		write (fd, &dash, 1);
	}
	if (n >= 10)
		size += ft_putnbr_fd(n / 10, fd);
	modulo = n % 10 + 48;
	write(fd, &modulo, 1);
	size++;
	return (size);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	modulo;
	int		size;

	size = 0;
	if (n >= 10)
		size += ft_putnbr_fd(n / 10, fd);
	modulo = n % 10 + 48;
	write(fd, &modulo, 1);
	size++;
	return (size);
}
