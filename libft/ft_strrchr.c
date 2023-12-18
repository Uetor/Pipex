/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:11:05 by pedrogon          #+#    #+#             */
/*   Updated: 2023/05/16 19:23:43 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(str);
	if ((char)c == '\0')
		return (str + i);
	while (i + 1 > 0)
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
		i--;
	}
	return (NULL);
}
