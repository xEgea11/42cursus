/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:05:10 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/25 21:58:53 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	to_hex(unsigned int i)
{
	int		remainder;
	char	*base16;
	int		size;

	base16 = "0123456789abcdef";
	size = 0;
	remainder = 0;
	if (i < 16)
	{
		size += ft_putchar_fd(base16[i], 1);
		return (size);
	}
	else
	{
		size += to_hex(i / 16);
		remainder = i % 16;
		size += ft_putchar_fd(base16[remainder], 1);
	}
	return (size);
}	

int	to_hex_up(unsigned int i)
{
	int		remainder;
	char	*base16;
	int		size;

	base16 = "0123456789ABCDEF";
	size = 0;
	remainder = 0;
	if (i < 16)
	{
		size += ft_putchar_fd(base16[i], 1);
		return (size);
	}
	else
	{
		size += to_hex_up(i / 16);
		remainder = i % 16;
		size += ft_putchar_fd(base16[remainder], 1);
	}
	return (size);
}	

int	ptrhx(unsigned long int i)
{
	int		remainder;
	int		size;
	char	*base16;

	base16 = "0123456789abcdef";
	size = 0;
	if (i == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	if (i < 16)
	{
		write(1, "0x", 2);
		size += ft_putchar_fd(base16[i], 1) + 2;
		return (size);
	}
	else
	{
		size += ptrhx(i / 16);
		remainder = i % 16;
		size += ft_putchar_fd(base16[remainder], 1);
	}
	return (size);
}	
