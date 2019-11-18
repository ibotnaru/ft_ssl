/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:55:37 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/13 02:11:17 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void		call_sha256(char *str)
{
	t_sha256		sha256;
	char			*newmessage;
	unsigned long	len;
	unsigned long	final_len;

	ft_bzero(&sha256, sizeof(t_sha256));
	len = (unsigned long)ft_strlen(str);
	final_len = appendlen_step1(str);
	newmessage = expandmessage_step2(str, final_len, len);
	algorithmsha256_step3(newmessage, &sha256, final_len);
	conversion_step6(&sha256);
	printhash_step7(&sha256);
}

void		call_md5(char *str)
{
	t_init			strct;
	unsigned long	final_len;
	char			*new_message;
	unsigned long	len;
	unsigned long	i;

	i = 0;
	len = (unsigned long)ft_strlen(str);
	final_len = step1_appendlen(str);
	new_message = step2_expandmessage(str, final_len, len);
	step4_algorithm(final_len, new_message, &strct, i);
	step5_printhash(&strct);
}
