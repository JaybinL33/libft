/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:17:24 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/27 10:45:50 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_byte;

	s_byte = s;
	while (n--)
		*s_byte++ = c;
	return (s);
}
