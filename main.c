/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:29:11 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/13 02:10:13 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

/*
** Function checks if we can find md5 or sha256 as given arguments; it should
** be second param (after executable ./ft_ssl); keeps the value of the
** hash algorithm in structure; In case of error prints error message.
*/

void			parsing_hash(t_struct *strct, char **av)
{
	if (ft_strcmp(av[1], "md5") == 0)
		strct->hash = "MD5";
	else if (ft_strcmp(av[1], "sha256") == 0)
		strct->hash = "SHA256";
	else
	{
		ft_putstr(ERR_HASH);
		exit(0);
	}
}

int				main(int ac, char **av)
{
	t_struct	strct;
	int			fd;

	fd = 0;
	if (ac < 2)
	{
		ft_putstr(ERR_USG);
		exit(0);
	}
	ft_bzero(&strct, sizeof(t_struct));
	strct.total_params = ac;
	parsing_hash(&strct, av);
	if (ac == 2)
	{
		fd = read(0, strct.mssg, MAX);
		if (ft_strcmp(strct.hash, "SHA256") == 0)
			call_sha256(strct.mssg);
		else if (ft_strcmp(strct.hash, "MD5") == 0)
			call_md5(strct.mssg);
		ft_putstr("\n");
		exit(1);
	}
	parsing_flags(av, &strct);
	return (0);
}
