/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 08:44:57 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/27 10:24:36 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	const char	*s_curr;

	s_curr = s;
	while (*s_curr)
		s_curr++;
	return (s_curr - s);
}
