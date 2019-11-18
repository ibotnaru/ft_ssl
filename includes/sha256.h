/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:57:38 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/12 19:14:27 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H
# include "../libft/libft.h"
# include "ft_ssl.h"

/*
** Hash initialization. The initial hash values H0-H7 are the first 32 bits
** of the fractional parts of the square roots of the first 8 prime numbers,
** represented in hex :
*/

# define H0 0x6a09e667
# define H1 0xbb67ae85
# define H2 0x3c6ef372
# define H3 0xa54ff53a
# define H4 0x510e527f
# define H5 0x9b05688c
# define H6 0x1f83d9ab
# define H7 0x5be0cd19

/*
** Define the rotation
*/

# define SHR(x, n) (x >> n)
# define RL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
# define RR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

/*
** MAIN LOOP
** Six logical functions are used in SHA-256.
** Each of these functions operates on 32-bit words and produces
** a 32-bit word as output. Each function is dened as follows :
*/

# define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SUM0(x) (RR(x, 2) ^ RR(x, 13) ^ RR(x, 22))
# define SUM1(x) (RR(x, 6) ^ RR(x, 11) ^ RR(x, 25))
# define SIG0(x) (RR(x, 7) ^ RR(x, 18) ^ SHR(x, 3))
# define SIG1(x) (RR(x, 17) ^ RR(x, 19) ^ SHR(x, 10))

/*
** a, b, c, d, e, f, g, h - main workink variables used in the MAIN LOOP
*/

typedef struct		s_sha256
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;

	char			*str_a;
	char			*str_b;
	char			*str_c;
	char			*str_d;
	char			*str_e;
	char			*str_f;
	char			*str_g;
	char			*str_h;
}					t_sha256;

/*
** sha256 step by step
*/

void				call_sha256(char *str);
unsigned long		appendlen_step1(char *message);
char				*expandmessage_step2(char *message, unsigned long final_len,
						unsigned long len);
void				algorithmsha256_step3(char *msg, t_sha256 *sha256,
						unsigned long flen);
void				mainloop_step4(char *chunk, t_sha256 *sha256);
unsigned int		*initsha256_k(void);
void				shuffle_step5(unsigned int *m, t_sha256 *sha256);
void				shuffle(unsigned int *m, t_sha256 *sha256);
void				conversion_step6(t_sha256 *sha256);
void				printhash_step7(t_sha256 *sha256);

#endif
