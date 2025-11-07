/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaigonza <jaigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:40:41 by jaigonza          #+#    #+#             */
/*   Updated: 2025/06/28 13:41:26 by jaigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*append_char(char *old_msg, size_t *old_len, char c)
{
	char	*new_msg;

	new_msg = malloc((*old_len + 2) * sizeof(char));
	if (!new_msg)
		return (NULL);
	if (old_msg)
	{
		ft_memcpy(new_msg, old_msg, *old_len);
		free(old_msg);
	}
	new_msg[*old_len] = c;
	new_msg[*old_len + 1] = '\0';
	(*old_len)++;
	return (new_msg);
}
