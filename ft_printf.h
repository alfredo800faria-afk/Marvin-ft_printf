/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 08:03:55 by srusso-b          #+#    #+#             */
/*   Updated: 2025/12/01 14:19:39 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

int	ft_putchar_len(char c);
int	ft_putstr_len(char *s);
int	ft_putnbr_len(int nb);
int	ft_putnbr_uns(unsigned int nb);
int	ft_put_hex(size_t nb, char *base);
int	ft_put_ptr(void *ptr);
int	ft_putnbr_base(unsigned int nb, char fmt);
int	ft_printf(const char *fmt, ...);

#endif
