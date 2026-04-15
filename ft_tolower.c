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

/* Avoids branch misprediction via a single unsigned comparison
and bit manipulation.

Assumes ASCII encoding (exploits the 1-bit difference at Bit 5). */
int	ft_tolower(int c)
{
	return (c ^ (((unsigned)c - 'A' <= 'Z' - 'A') << 5));
}
