/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:16:16 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/01 16:16:16 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(s) + 1;
	dst = malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	return (ft_memcpy(dst, s, size));
}
