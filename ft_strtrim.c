/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:54:44 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/06 11:54:44 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s2_len;
	size_t	start;
	size_t	end;
	char	*s2;

	end = ft_strlen(s1);
	start = 0;
	while (end > start && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s2_len = end - start;
	s2 = malloc(sizeof(char) * (s2_len + 1));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1 + start, s2_len);
	s2[s2_len] = '\0';
	return (s2);
}
