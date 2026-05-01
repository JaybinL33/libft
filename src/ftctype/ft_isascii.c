/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:06:25 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/04 15:06:25 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftctype.h"

/*
 * 127 is 0b01111111. ~127 isolates bits outside the 7-bit ASCII range.
 */
int	ft_isascii(int c)
{
	return (!(c & ~127));
}
