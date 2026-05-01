/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 10:43:39 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/04 10:43:39 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Range compression: 0 <= c - '0' <= 9.
 * Values below '0' underflow to MAX_UINT, naturally failing the check.
 */
int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' <= '9' - '0');
}
