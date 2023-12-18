/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:33:45 by pedrogon          #+#    #+#             */
/*   Updated: 2023/05/19 13:37:48 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*x;

	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i -1]))
		i--;
	x = ft_substr(s1, 0, i);
	if (!x)
		return (0);
	return (x);
}
