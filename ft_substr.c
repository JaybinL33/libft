/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:28:55 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/04 18:28:55 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;
	size_t	sub_s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		sub_s_len = 0;
	else if (s_len - start >= len)
		sub_s_len = len;
	else
		sub_s_len = s_len - start;
	sub_s = malloc(sizeof(char) * (sub_s_len + 1));
	if (!sub_s)
		return (NULL);
	ft_memcpy(sub_s, s + start, sub_s_len);
	sub_s[sub_s_len] = '\0';
	return (sub_s);
}
