/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:06:18 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/28 11:57:45 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Branchless case conversion:
 * 1) Range check: (unsigned)c - 'a' <= 'z' - 'a' returns 1 if lowercase.
 * 2) Bit flip: 1 << 5 evaluates to 32 (0b00100000).
 *    XORing with Bit 5 toggles lowercase to uppercase.
 */
int	ft_toupper(int c)
{
	return (c ^ (((unsigned)c - 'a' <= 'z' - 'a') << 5));
}
