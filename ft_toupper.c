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

/* Avoids branch misprediction via a single unsigned comparison
and bit manipulation.

Assumes ASCII encoding (exploits the 1-bit difference at Bit 5). */
int	ft_toupper(int c)
{
	return (c ^ (((unsigned)c - 'a' <= 'z' - 'a') << 5));
}
