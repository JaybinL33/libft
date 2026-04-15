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
#include <errno.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && (size_t)-1 / size < nmemb)
	{
		errno = ENOMEM;
		return (NULL);
	}
	size *= nmemb;
	if (!size)
		return (malloc(1));
	p = malloc(size);
	if (!p)
		return (p);
	return (ft_memset(p, 0, size));
}
