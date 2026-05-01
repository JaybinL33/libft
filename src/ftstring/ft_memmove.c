/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:39:49 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/27 13:43:03 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include <stddef.h>
#include <stdint.h>

/*
 * Single unsigned comparison for memory overlap.
 * Compresses the disjoint bounds (n <= src - dest <= -n) into one check.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_byte;
	const char	*src_byte;

	if (dest == src)
		return (dest);
	if ((uintptr_t)src - (uintptr_t)dest - n <= -2 * n)
		return (ft_memcpy(dest, src, n));
	if (dest < src)
	{
		dest_byte = dest;
		src_byte = src;
		while (n--)
			*dest_byte++ = *src_byte++;
		return (dest);
	}
	dest_byte = dest + n - 1;
	src_byte = src + n - 1;
	while (n--)
		*dest_byte-- = *src_byte--;
	return (dest);
}
