/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:09:10 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/07 17:35:01 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcustom.h"
#include "ftstring.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	ssize_t	bytes_written;

	len = ft_strlen(s);
	while (len)
	{
		bytes_written = write(fd, s, len);
		if (bytes_written <= 0)
			return ;
		s += bytes_written;
		len -= bytes_written;
	}
}
