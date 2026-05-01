/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:05:29 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/28 11:57:43 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Branchless case conversion:
 * 1) Range check: (unsigned)c - 'A' <= 'Z' - 'A' returns 1 if uppercase.
 * 2) Bit flip: 1 << 5 evaluates to 32 (0b00100000).
 *    XORing with Bit 5 toggles uppercase to lowercase.
 */
int	ft_tolower(int c)
{
	return (c ^ (((unsigned)c - 'A' <= 'Z' - 'A') << 5));
}
