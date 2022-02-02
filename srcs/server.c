/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:56:30 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/02 14:18:07 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_receive_message(int signal)
{
	static int				current_bit;
	static unsigned char	character;

	if (signal == SIGUSR2)
		character = character | (1 << current_bit);
	current_bit++;
	if (current_bit == 8)
	{
		ft_putchar_fd(character, 1);
		current_bit = 0;
		character = 0;
	}
}

void	ft_display_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

int	main(void)
{
	ft_display_pid();
	signal(SIGUSR1, ft_receive_message);
	signal(SIGUSR2, ft_receive_message);
	while (1)
		pause();
}
