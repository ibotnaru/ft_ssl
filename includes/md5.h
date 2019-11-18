/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:20:23 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/13 02:12:24 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H
# include "../libft/libft.h"

# define A	(md5->a)
# define B	(md5->b)
# define C	(md5->c)
# define D	(md5->d)

/*
** Define the constants and auxiliar functions which we will
** use later in our rounds (1-4) to hash the message.
*/

# define S11 7
# define S12 12
# define S13 17
# define S14 22

# define S21 5
# define S22 9
# define S23 14
# define S24 20

# define S31 4
# define S32 11
# define S33 16
# define S34 23

# define S41 6
# define S42 10
# define S43 15
# define S44 21

# define F(x, y, z)	((x & y) | ((~x) & z))
# define G(x, y, z)	((x & z) | (y & (~z)))
# define H(x, y, z)	(x ^ y ^ z)
# define I(x, y, z)	(y ^ (x | (~z)))

# define RL(x, n)	(((x) << (n)) | ((x) >> (32 - (n))))

/*
** Main structure, keeps the values of buffers.
*/

typedef struct		s_init
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;

	char			*str_a;
	char			*str_b;
	char			*str_c;
	char			*str_d;

}					t_init;

/*
** MD5 step by step (1-4 steps)
*/

unsigned long		step1_appendlen(char *message);
char				*step2_expandmessage(char *message,
						unsigned long final_len, unsigned long len);
void				step3_init_wordbuffers(unsigned int *a,
						unsigned int *b, unsigned int *c, unsigned int *d);
void				step4_algorithm(unsigned long final_len,
						char *new_message, t_init *md5, unsigned long i);
void				rounds1234(char *new_message, t_init *md5, int i);

/*
** MD5 rounds 1, 2, 3, 4
*/

uint32_t			*init_table(void);
void				round_1(unsigned int *chunk, t_init *md5);
void				round_2(unsigned int *chunk, t_init *md5);
void				round_3(unsigned int *chunk, t_init *md5);
void				round_4(unsigned int *chunk, t_init *md5);

/*
** Step 5, printing final result (the hash)
*/

void				step5_printhash(t_init *md5);
void				ft_puthash(char	*str);

/*
** Conversion functions
*/

char				*ft_itoa_base_ux(uintmax_t value, int base);
char				*itoa_filler_b(char *tab, uintmax_t value, int base);
void				itoa_filler_init(uintmax_t *tmp,
						uintmax_t value, int *size, int base);

#endif
