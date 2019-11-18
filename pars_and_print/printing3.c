/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:48:28 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/13 02:10:06 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	print_str(t_struct *s, char *str)
{
	if (ft_strcmp(s->hash, "MD5") == 0)
	{
		ft_putstr("MD5 (\"");
		ft_putstr(str);
		ft_putstr("\") = ");
		call_md5(str);
	}
	else if (ft_strcmp(s->hash, "SHA256") == 0)
	{
		ft_putstr("SHA256 (\"");
		ft_putstr(str);
		ft_putstr("\") = ");
		call_sha256(str);
	}
}

void	print_null(t_struct *s)
{
	if (ft_strcmp(s->hash, "SHA256") == 0)
		call_sha256("");
	else if (ft_strcmp(s->hash, "MD5") == 0)
		call_md5("");
	ft_putstr("\n");
}

void	print_file_md5_sha256(t_struct *s, char **av, int i)
{
	if (ft_strcmp(s->hash, "MD5") == 0)
	{
		ft_putstr("MD5 (");
		ft_putstr(av[i]);
		ft_putstr(") = ");
		call_md5(s->mssg);
	}
	else if (ft_strcmp(s->hash, "SHA256") == 0)
	{
		ft_putstr("SHA256 (");
		ft_putstr(av[i]);
		ft_putstr(") = ");
		call_sha256(s->mssg);
	}
}
