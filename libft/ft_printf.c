/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:56:45 by pedrogon          #+#    #+#             */
/*   Updated: 2023/09/20 21:41:27 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversion(char c, va_list args, int len)
{
	if (c == 'c')
		len = len + ft_putchar(va_arg (args, int));
	else if (c == 's')
		len = len + ft_putstr(va_arg (args, char *));
	else if (c == 'p')
	{
		len += 2;
		write (1, "0x", 2);
		len = len + ft_pointer(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		len = len + ft_decimal(va_arg (args, int), 10, "0123456789");
	else if (c == 'u')
		len = len + ft_unsigned_int(va_arg (args, unsigned int));
	else if (c == 'x')
		len = len + hexalower(va_arg (args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = len + hexauper(va_arg (args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
	{
		len++;
		ft_putchar('%');
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start (args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = conversion (str[i], args, len);
		}
		else
		{
			write (1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}
