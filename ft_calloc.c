/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:04:36 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/01 14:04:36 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
 * Safe multiplication check: (size_t)-1 is 0b11...11 (MAX).
 * Logic: If (MAX / size < nmemb), then (size * nmemb) would overflow.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && (size_t)-1 / size < nmemb)
		return (NULL);
	size *= nmemb;
	if (!size)
		return (malloc(1));
	p = malloc(size);
	if (!p)
		return (p);
	return (ft_memset(p, 0, size));
}
