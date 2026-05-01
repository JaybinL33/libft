/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:03:26 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/04 08:04:21 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftctype.h"

/*
 * 1) Case folding: 'a' - 'A' is 32 (0b00100000). Bitwise OR with 0b00100000
 *    forces uppercase letters into their lowercase equivalents.
 * 2) Range compression: 0 <= c - 'a' <= 'z' - 'a'.
 *    Values below 'a' underflow to MAX_UINT, naturally failing the check.
 */
int	ft_isalpha(int c)
{
	return (((unsigned)c | ('a' - 'A')) - 'a' <= 'z' - 'a');
}
