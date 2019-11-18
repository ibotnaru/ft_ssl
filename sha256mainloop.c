/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256mainloop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:25:07 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/13 02:05:24 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/sha256.h"

void					mainloop_step4(char *chunk, t_sha256 *sha256)
{
	int					i;
	int					j;
	unsigned int		m[64];

	i = 0;
	j = 0;
	while (i <= 15)
	{
		m[i] = ((unsigned char)chunk[j] << 24) |
			((unsigned char)chunk[j + 1] << 16) |
			((unsigned char)chunk[j + 2] << 8) | ((unsigned char)chunk[j + 3]);
		i++;
		j += 4;
	}
	while (i < 64)
	{
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
		i++;
	}
	shuffle_step5(m, sha256);
}

/*
** Initialize array of round constants: (first 32 bits of the fractional parts
** of the cube roots of the first 64 prime numbers, represented in hexdecimal:
*/

unsigned int			*initsha256_k(void)
{
	static unsigned int		sha256_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
	};

	return (sha256_k);
}

void					shuffle(unsigned int *m, t_sha256 *sha256)
{
	unsigned int	t1;
	unsigned int	t2;
	unsigned int	*k;
	int				i;

	i = 0;
	k = initsha256_k();
	while (i < 64)
	{
		t1 = sha256->h + SUM1(sha256->e) + CH(sha256->e, sha256->f, sha256->g)
			+ k[i] + m[i];
		t2 = SUM0(sha256->a) + MAJ(sha256->a, sha256->b, sha256->c);
		sha256->h = sha256->g;
		sha256->g = sha256->f;
		sha256->f = sha256->e;
		sha256->e = sha256->d + t1;
		sha256->d = sha256->c;
		sha256->c = sha256->b;
		sha256->b = sha256->a;
		sha256->a = t1 + t2;
		i++;
	}
}

void					shuffle_step5(unsigned int *m, t_sha256 *sha256)
{
	t_sha256		tmp;

	tmp.a = sha256->a;
	tmp.b = sha256->b;
	tmp.c = sha256->c;
	tmp.d = sha256->d;
	tmp.e = sha256->e;
	tmp.f = sha256->f;
	tmp.g = sha256->g;
	tmp.h = sha256->h;
	shuffle(m, sha256);
	sha256->a += tmp.a;
	sha256->b += tmp.b;
	sha256->c += tmp.c;
	sha256->d += tmp.d;
	sha256->e += tmp.e;
	sha256->f += tmp.f;
	sha256->g += tmp.g;
	sha256->h += tmp.h;
}
