/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 07:14:23 by srusso            #+#    #+#             */
/*   Updated: 2025/12/01 18:34:13 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flags(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_len((char)va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_len(va_arg(args, char *));
	else if (c == 'p')
		count += ft_put_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_len(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_uns(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), c);
	else if (c == '%')
		count += ft_putchar_len('%');
	else
		count = -1;
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	va_start(args, fmt);
	if (!fmt)
		return (-1);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (!fmt[i + 1])
				return (va_end(args), -1);
			count += ft_flags(fmt[++i], args);
		}
		else
			count += ft_putchar_len((int)fmt[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <limits.h>

int main(void)
{
	int nbr = INT_MAX;
	char str[] = "Hello MArvin";
	ft_printf("%d\n", nbr);
	ft_printf("%s\n", str);
	ft_printf("%x\n", nbr);
	ft_printf("%p\n", nbr);
	ft_printf("%u\n", nbr);
	printf("%u\n", nbr);
	ft_printf("%%\n");

	ft_printf("%u\n", 
	ft_printf("%d\n",
	ft_printf("%x\n",
	ft_printf("%X\n", 50000))));

	printf("%u\n", 
	printf("%d\n",printf("%x\n", printf("%X\n", 50000))));
	return (0);
}
*/
