/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:55:00 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/02 10:58:56 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../srcs/libft/libft.h"
# include <signal.h>

void	ft_display_pid(void);
void	ft_send_message(int pid, char *str);
void	ft_receive_message(int signal);

#endif