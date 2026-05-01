/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:29:51 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/27 10:24:51 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_byte;
	const char	*src_byte;

	dest_byte = dest;
	src_byte = src;
	while (n--)
		*dest_byte++ = *src_byte++;
	return (dest);
}
