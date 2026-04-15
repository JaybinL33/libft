/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:17:52 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/28 09:17:52 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_byte = s;

	c = (unsigned char)c;
	while (n-- && *s_byte != c)
		s_byte++;
	if (!n)
		return ((char *)s_byte);
	return (NULL);
}
