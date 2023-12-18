/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:02:51 by pedrogon          #+#    #+#             */
/*   Updated: 2023/05/16 20:36:46 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			end;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len < ft_strlen(s))
		end = start + len;
	else
		end = ft_strlen(s);
	str = malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
