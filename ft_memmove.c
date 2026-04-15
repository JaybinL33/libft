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

#include "libft.h"
#include <stddef.h>
#include <stdint.h>

/* Let U_DIFF = (uintptr_t)src - (uintptr_t)dest

No-overlap unsigned modular arithmetic range: n <= U_DIFF <= -n

Added n - 1 or -n to the range for compressing the two-sided check
into a single unsigned comparison:

1) 2n - 1 <= U_DIFF + n - 1 <= -1
2) 0 <= U_DIFF - n <= -2n

Since '0(MIN) <=' and '<= -1(MAX)' are implicitly always true
in unsigned modular arithmetic, they are safely omitted:

1) 2n - 1 <= U_DIFF + n - 1
2) U_DIFF - n <= -2n */
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
