/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:29:27 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/27 10:24:48 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (*s && *(unsigned char *)s != c)
		s++;
	if (*(unsigned char *)s == c)
		return ((char *)s);
	return (NULL);
}
