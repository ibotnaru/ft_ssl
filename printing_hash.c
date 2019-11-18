/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:58:54 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/12 20:58:33 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/md5.h"
#include "includes/sha256.h"

/*
** Printing functions for md5 and sha256 convert the hash buffers from
** (unisigned int) to string in hash representation and print final
** result.
*/

/*
** Printing md5 hash
*/

void				step5_printhash(t_init *md5)
{
	md5->a = (uintmax_t)md5->a;
	md5->b = (uintmax_t)md5->b;
	md5->c = (uintmax_t)md5->c;
	md5->d = (uintmax_t)md5->d;
	md5->str_a = ft_itoa_base_ux(md5->a, 16);
	md5->str_b = ft_itoa_base_ux(md5->b, 16);
	md5->str_c = ft_itoa_base_ux(md5->c, 16);
	md5->str_d = ft_itoa_base_ux(md5->d, 16);
	ft_puthash(md5->str_a);
	ft_puthash(md5->str_b);
	ft_puthash(md5->str_c);
	ft_puthash(md5->str_d);
}

void				ft_puthash(char *str)
{
	ft_putchar(str[6]);
	ft_putchar(str[7]);
	ft_putchar(str[4]);
	ft_putchar(str[5]);
	ft_putchar(str[2]);
	ft_putchar(str[3]);
	ft_putchar(str[0]);
	if (ft_strlen(str) < 8)
		ft_putchar('0');
	ft_putchar(str[1]);
	free(str);
}

/*
** Printing sha256 hashsum
*/

void				printhash_step7(t_sha256 *sha256)
{
	ft_putstr(sha256->str_a);
	ft_putstr(sha256->str_b);
	ft_putstr(sha256->str_c);
	ft_putstr(sha256->str_d);
	ft_putstr(sha256->str_e);
	ft_putstr(sha256->str_f);
	ft_putstr(sha256->str_g);
	ft_putstr(sha256->str_h);
	free(sha256->str_a);
	free(sha256->str_b);
	free(sha256->str_c);
	free(sha256->str_d);
	free(sha256->str_e);
	free(sha256->str_f);
	free(sha256->str_g);
	free(sha256->str_h);
}

void				conversion_step6(t_sha256 *sha256)
{
	sha256->str_a = ft_itoa_base_ux((uintmax_t)sha256->a, 16);
	sha256->str_b = ft_itoa_base_ux((uintmax_t)sha256->b, 16);
	sha256->str_c = ft_itoa_base_ux((uintmax_t)sha256->c, 16);
	sha256->str_d = ft_itoa_base_ux((uintmax_t)sha256->d, 16);
	sha256->str_e = ft_itoa_base_ux((uintmax_t)sha256->e, 16);
	sha256->str_f = ft_itoa_base_ux((uintmax_t)sha256->f, 16);
	sha256->str_g = ft_itoa_base_ux((uintmax_t)sha256->g, 16);
	sha256->str_h = ft_itoa_base_ux((uintmax_t)sha256->h, 16);
}
