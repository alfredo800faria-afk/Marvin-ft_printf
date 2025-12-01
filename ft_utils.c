/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:18:16 by srusso-b          #+#    #+#             */
/*   Updated: 2025/12/01 18:07:04 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_len(char *s)
{
	unsigned int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_len(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_len(int nb)
{
	long	n;
	int		count;

	n = (long)nb;
	count = 0;
	if (n < 0)
	{
		n = -n;
		count += ft_putchar_len('-');
	}
	if (n >= 10)
		count += ft_putnbr_len(n / 10);
	count += ft_putchar_len('0' + (n % 10));
	return (count);
}

int	ft_putnbr_uns(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_uns(nb / 10);
	count += ft_putchar_len('0' + (nb % 10));
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	unsigned long	nb;
	int				count;

	nb = (size_t)ptr;
	if (!nb)
		return (ft_putstr_len("(nil)"));
	count = 0;
	count += ft_putstr_len("0x");
	count += ft_put_hex(nb, "0123456789abcdef");
	return (count);
}
