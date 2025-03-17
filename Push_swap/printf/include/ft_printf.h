/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:19:22 by cbouyer           #+#    #+#             */
/*   Updated: 2025/01/16 17:32:00 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_hex_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_print_ptr(uintptr_t ptr);
int		ft_putchar(int n);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_printnbr(int n);
int		ft_printpercent(void);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
#endif
