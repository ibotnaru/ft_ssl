/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5steps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:19:50 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/13 02:12:28 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/md5.h"

unsigned long	step1_appendlen(char *message)
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

char			*step2_expandmessage(char *message, unsigned long final_len,
				unsigned long len)
{
	char				*new_message;
	unsigned long		i;

	i = -1;
	new_message = ft_memalloc(final_len);
	while (++i < len)
		new_message[i] = message[i];
	((unsigned char *)new_message)[len] = 128;
	((unsigned long *)new_message)[final_len / 8 - 1] = len * 8;
	return (new_message);
}

void			step3_init_wordbuffers(unsigned int *a,
					unsigned int *b, unsigned int *c, unsigned int *d)
{
	*a = 0x67452301;
	*b = 0xefcdab89;
	*c = 0x98badcfe;
	*d = 0x10325476;
}

void			step4_algorithm(unsigned long final_len,
		char *new_message, t_init *md5, unsigned long i)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;

	i = 0;
	step3_init_wordbuffers(&a, &b, &c, &d);
	while (i < final_len)
	{
		md5->a = a;
		md5->b = b;
		md5->c = c;
		md5->d = d;
		rounds1234(new_message, md5, i);
		a += md5->a;
		b += md5->b;
		c += md5->c;
		d += md5->d;
		i += 64;
	}
	md5->a = a;
	md5->b = b;
	md5->c = c;
	md5->d = d;
	free(new_message);
}

void			rounds1234(char *new_message, t_init *md5, int i)
{
	round_1((unsigned int *)&new_message[i], md5);
	round_2((unsigned int *)&new_message[i], md5);
	round_3((unsigned int *)&new_message[i], md5);
	round_4((unsigned int *)&new_message[i], md5);
}
