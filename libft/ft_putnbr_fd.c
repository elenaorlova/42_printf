/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:31:12 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/05 15:31:13 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putnbr_fd(-214748364, fd);
		ft_putchar_fd('8', fd);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb < 10)
			ft_putchar_fd('0' + nb, fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd(nb % 10 + '0', fd);
		}
	}
}
