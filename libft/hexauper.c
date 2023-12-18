/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexauper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:18:13 by pedrogon          #+#    #+#             */
/*   Updated: 2023/09/20 21:40:39 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexauper(unsigned int x, char *hexa)
{
	int	len;

	len = 0;
	if (x >= 16)
		len += hexauper (x / 16, hexa);
	write (1, &hexa[x % 16], 1);
	len ++;
	return (len);
}
