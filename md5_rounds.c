/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_rounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:56:53 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/08 18:57:15 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/md5.h"

uint32_t		*init_table(void)
{
	static uint32_t	k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a,
	0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340,
	0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
	0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
	0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
	0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
	};

	return (k);
}

void			round_1(unsigned int *chunk, t_init *md5)
{
	uint32_t	*k;

	k = init_table();
	A = B + RL((A + F(B, C, D) + chunk[0] + k[0]), S11);
	D = A + RL((D + F(A, B, C) + chunk[1] + k[1]), S12);
	C = D + RL((C + F(D, A, B) + chunk[2] + k[2]), S13);
	B = C + RL((B + F(C, D, A) + chunk[3] + k[3]), S14);
	A = B + RL((A + F(B, C, D) + chunk[4] + k[4]), S11);
	D = A + RL((D + F(A, B, C) + chunk[5] + k[5]), S12);
	C = D + RL((C + F(D, A, B) + chunk[6] + k[6]), S13);
	B = C + RL((B + F(C, D, A) + chunk[7] + k[7]), S14);
	A = B + RL((A + F(B, C, D) + chunk[8] + k[8]), S11);
	D = A + RL((D + F(A, B, C) + chunk[9] + k[9]), S12);
	C = D + RL((C + F(D, A, B) + chunk[10] + k[10]), S13);
	B = C + RL((B + F(C, D, A) + chunk[11] + k[11]), S14);
	A = B + RL((A + F(B, C, D) + chunk[12] + k[12]), S11);
	D = A + RL((D + F(A, B, C) + chunk[13] + k[13]), S12);
	C = D + RL((C + F(D, A, B) + chunk[14] + k[14]), S13);
	B = C + RL((B + F(C, D, A) + chunk[15] + k[15]), S14);
}

void			round_2(unsigned int *chunk, t_init *md5)
{
	uint32_t	*k;

	k = init_table();
	A = B + RL((A + G(B, C, D) + chunk[1] + k[16]), S21);
	D = A + RL((D + G(A, B, C) + chunk[6] + k[17]), S22);
	C = D + RL((C + G(D, A, B) + chunk[11] + k[18]), S23);
	B = C + RL((B + G(C, D, A) + chunk[0] + k[19]), S24);
	A = B + RL((A + G(B, C, D) + chunk[5] + k[20]), S21);
	D = A + RL((D + G(A, B, C) + chunk[10] + k[21]), S22);
	C = D + RL((C + G(D, A, B) + chunk[15] + k[22]), S23);
	B = C + RL((B + G(C, D, A) + chunk[4] + k[23]), S24);
	A = B + RL((A + G(B, C, D) + chunk[9] + k[24]), S21);
	D = A + RL((D + G(A, B, C) + chunk[14] + k[25]), S22);
	C = D + RL((C + G(D, A, B) + chunk[3] + k[26]), S23);
	B = C + RL((B + G(C, D, A) + chunk[8] + k[27]), S24);
	A = B + RL((A + G(B, C, D) + chunk[13] + k[28]), S21);
	D = A + RL((D + G(A, B, C) + chunk[2] + k[29]), S22);
	C = D + RL((C + G(D, A, B) + chunk[7] + k[30]), S23);
	B = C + RL((B + G(C, D, A) + chunk[12] + k[31]), S24);
}

void			round_3(unsigned int *chunk, t_init *md5)
{
	uint32_t	*k;

	k = init_table();
	A = B + RL((A + H(B, C, D) + chunk[5] + k[32]), S31);
	D = A + RL((D + H(A, B, C) + chunk[8] + k[33]), S32);
	C = D + RL((C + H(D, A, B) + chunk[11] + k[34]), S33);
	B = C + RL((B + H(C, D, A) + chunk[14] + k[35]), S34);
	A = B + RL((A + H(B, C, D) + chunk[1] + k[36]), S31);
	D = A + RL((D + H(A, B, C) + chunk[4] + k[37]), S32);
	C = D + RL((C + H(D, A, B) + chunk[7] + k[38]), S33);
	B = C + RL((B + H(C, D, A) + chunk[10] + k[39]), S34);
	A = B + RL((A + H(B, C, D) + chunk[13] + k[40]), S31);
	D = A + RL((D + H(A, B, C) + chunk[0] + k[41]), S32);
	C = D + RL((C + H(D, A, B) + chunk[3] + k[42]), S33);
	B = C + RL((B + H(C, D, A) + chunk[6] + k[43]), S34);
	A = B + RL((A + H(B, C, D) + chunk[9] + k[44]), S31);
	D = A + RL((D + H(A, B, C) + chunk[12] + k[45]), S32);
	C = D + RL((C + H(D, A, B) + chunk[15] + k[46]), S33);
	B = C + RL((B + H(C, D, A) + chunk[2] + k[47]), S34);
}

void			round_4(unsigned int *chunk, t_init *md5)
{
	uint32_t	*k;

	k = init_table();
	A = B + RL((A + I(B, C, D) + chunk[0] + k[48]), S41);
	D = A + RL((D + I(A, B, C) + chunk[7] + k[49]), S42);
	C = D + RL((C + I(D, A, B) + chunk[14] + k[50]), S43);
	B = C + RL((B + I(C, D, A) + chunk[5] + k[51]), S44);
	A = B + RL((A + I(B, C, D) + chunk[12] + k[52]), S41);
	D = A + RL((D + I(A, B, C) + chunk[3] + k[53]), S42);
	C = D + RL((C + I(D, A, B) + chunk[10] + k[54]), S43);
	B = C + RL((B + I(C, D, A) + chunk[1] + k[55]), S44);
	A = B + RL((A + I(B, C, D) + chunk[8] + k[56]), S41);
	D = A + RL((D + I(A, B, C) + chunk[15] + k[57]), S42);
	C = D + RL((C + I(D, A, B) + chunk[6] + k[58]), S43);
	B = C + RL((B + I(C, D, A) + chunk[13] + k[59]), S44);
	A = B + RL((A + I(B, C, D) + chunk[4] + k[60]), S41);
	D = A + RL((D + I(A, B, C) + chunk[11] + k[61]), S42);
	C = D + RL((C + I(D, A, B) + chunk[2] + k[62]), S43);
	B = C + RL((B + I(C, D, A) + chunk[9] + k[63]), S44);
}
