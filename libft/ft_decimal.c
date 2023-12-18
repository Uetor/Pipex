/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:02:49 by pedrogon          #+#    #+#             */
/*   Updated: 2023/09/20 21:41:01 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_decimal(long int decimal, int len, char *sign)
{
	int	leng;

	leng = 0;
	if (decimal < 0)
	{
		write (1, "-", 1);
		leng++;
		decimal = decimal * -1;
	}
	if (decimal >= len)
		leng += ft_decimal(decimal / len, len, sign);
	write(1, &sign[decimal % len], 1);
	leng++;
	return (leng);
}
