/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:32:02 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/08 18:57:06 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Conversion of buffers A B C D from integer number (unsigned int)
** to string (char *) in hex representation.
*/

#include "includes/md5.h"

void		itoa_filler_init(uintmax_t *tmp,
				uintmax_t value, int *size, int base)
{
	*size = 0;
	*tmp = value;
	while (*tmp /= base)
		(*size)++;
	*size = *size + 1;
}

char		*itoa_filler_b(char *tab, uintmax_t value, int base)
{
	uintmax_t		tmp;
	int				size;
	char			*str;

	itoa_filler_init(&tmp, value, &size, base);
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % base];
		size--;
		value = value / base;
	}
	return (str);
}

char		*ft_itoa_base_ux(uintmax_t value, int base)
{
	char		*str;
	char		*rest;

	str = "0123456789abcdef";
	rest = itoa_filler_b(str, value, base);
	return (rest);
}
