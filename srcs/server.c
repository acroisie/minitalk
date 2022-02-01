/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:56:30 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/01 11:11:22 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_display_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

int	main(void)
{
	ft_display_pid();
	return (0);
}
