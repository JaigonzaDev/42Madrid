/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:59:22 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 15:00:21 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*
 * Extra libs
 */
# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_client
{
	int						ok;
	pid_t					pid;
	char					*message;
	int						ready;
}							t_client;

typedef struct s_server
{
	volatile sig_atomic_t	clean;
	volatile sig_atomic_t	c_pid;
	volatile sig_atomic_t	act_pid;
	volatile sig_atomic_t	current_char;
	volatile sig_atomic_t	bit_count;
	size_t					msg_size;
	char					*message;
}							t_server;

extern t_client				g_client;
extern t_server				g_server;
// SERVER
int							check_state(void);
void						server_loop(void);
void						server_config(void);
void						server_handler(int sig, siginfo_t *info,
								void *context);
void						save_message(int sig);
char						*append_char(char *old_msg, size_t *old_len,
								char c);

// CLIENT

void						send_config(void);
void						send_message_handler(int sig, siginfo_t *info,
								void *ucontext);
void						send_bit(pid_t server_pid, int bit);
void						send_char(pid_t server_pid, char c);
void						send_message(char *message, pid_t server_pid);
void						try_connection(void);
void						try_config(void);
void						try_connection_handler(int sig, siginfo_t *info,
								void *ucontext);

// Common
void						clean(void);
#endif