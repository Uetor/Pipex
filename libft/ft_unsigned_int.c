/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:04:45 by pedrogon          #+#    #+#             */
/*   Updated: 2023/09/20 21:39:40 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_int(unsigned int long n)
{
	int		len;
	char	x;

	len = 0;
	if (n >= 10)
		len += ft_unsigned_int (n / 10);
	len++;
	x = n % 10 + '0';
	write (1, &x, 1);
	return (len);
}
