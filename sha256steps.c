/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:24:02 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/12 21:00:59 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/sha256.h"

/*
** Init working variables with hash values.
** Take a chunk of 64bytes(64 by 64 until we rich the final_len) and send
** it to shuffle toghether with the working variables.
*/

void			algorithmsha256_step3(char *msg, t_sha256 *sha256,
												unsigned long flen)
{
	unsigned long	i;

	i = 0;
	sha256->a = H0;
	sha256->b = H1;
	sha256->c = H2;
	sha256->d = H3;
	sha256->e = H4;
	sha256->f = H5;
	sha256->g = H6;
	sha256->h = H7;
	while (i < flen)
	{
		mainloop_step4(&msg[i], sha256);
		i += 64;
	}
	free(msg);
}

char			*expandmessage_step2(char *message, unsigned long final_len,
				unsigned long len)
{
	char			*new_message;
	char			tmp;
	unsigned long	i;
	int				k;
	int				n;

	i = -1;
	new_message = ft_memalloc(final_len);
	while (++i < len)
		new_message[i] = message[i];
	((unsigned char *)new_message)[len] = 128;
	((unsigned long *)new_message)[final_len / 8 - 1] = len * 8;
	k = final_len - 8;
	n = final_len - 1;
	while (k < n)
	{
		tmp = new_message[k];
		new_message[k] = new_message[n];
		new_message[n] = tmp;
		k++;
		n--;
	}
	return (new_message);
}

unsigned long	appendlen_step1(char *message)
{
	unsigned long	final_len;
	unsigned long	msg_len;

	msg_len = (unsigned long)ft_strlen(message);
	if (msg_len % 64 == 0)
	{
		if (msg_len == 0)
			final_len = 64;
		else
			final_len = msg_len;
	}
	else if (msg_len % 64 < 56)
		final_len = 64 - msg_len % 64;
	else
		final_len = 64 + (64 - msg_len % 64);
	final_len += msg_len;
	return (final_len);
}
