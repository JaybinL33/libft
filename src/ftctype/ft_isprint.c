/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:17:44 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/28 08:56:32 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftctype.h"

/*
 * Range compression: 0 <= c - 32 <= 94.
 * Values below 32 underflow to MAX_UINT, naturally failing the check.
 */
int	ft_isprint(int c)
{
	return ((unsigned)c - 32 <= 126 - 32);
}
