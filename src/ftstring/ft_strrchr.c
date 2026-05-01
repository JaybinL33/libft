/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:19:50 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/28 13:56:01 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*u_s = (const unsigned char *)s;
	size_t				i;

	i = ft_strlen(s) + 1;
	c = (unsigned char)c;
	while (i--)
		if (u_s[i] == c)
			return ((char *)(u_s + i));
	return (NULL);
}
