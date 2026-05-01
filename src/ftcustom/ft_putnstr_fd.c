/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:32:22 by jungblee          #+#    #+#             */
/*   Updated: 2026/06/02 20:32:22 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcustom.h"

ssize_t	ft_putnstr_fd(char *s, int fd, size_t len)
{
	ssize_t	bytes_written;
	ssize_t	total_written;

	total_written = 0;
	while (len)
	{
		bytes_written = write(fd, s, len);
		if (bytes_written < 0)
			return (-1);
		if (!bytes_written)
			break ;
		s += bytes_written;
		total_written += bytes_written;
		len -= bytes_written;
	}
	return (total_written);
}
