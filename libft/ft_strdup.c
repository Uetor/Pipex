/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:54:22 by pedrogon          #+#    #+#             */
/*   Updated: 2023/05/15 10:55:51 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * i);
	if (!str)
		return (0);
	str = ft_memcpy(str, s, i);
	return (str);
}
