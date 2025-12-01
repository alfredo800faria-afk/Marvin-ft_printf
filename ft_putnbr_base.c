/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:21:53 by srusso-b          #+#    #+#             */
/*   Updated: 2025/12/01 17:39:23 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(size_t nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_put_hex(nb / 16, base);
	count += ft_putchar_len(base[nb % 16]);
	return (count);
}

int	ft_putnbr_base(unsigned int nb, char fmt)
{
	char	*base;
	int		count;

	count = 0;
	if (fmt == 'x')
		base = "0123456789abcdef";
	else if (fmt == 'X')
		base = "0123456789ABCDEF";
	else
		return (-1);
	if (nb >= 16)
		count += ft_putnbr_base(nb / 16, fmt);
	count += ft_putchar_len(base[nb % 16]);
	return (count);
}
