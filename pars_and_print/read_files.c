/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:44:08 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/12 19:13:44 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		read_file_r(t_struct *s, char **av, int i)
{
	int		fd;

	fd = 0;
	while (++i < s->total_params)
	{
		if ((fd = open(av[i], O_RDONLY)) == EOF)
			print_error_not_file(s, av, i);
		else
		{
			fd = open(av[i], O_RDONLY);
			fd = read(fd, s->mssg, MAX);
			s->mssg[fd + 1] = '\0';
			if (ft_strcmp(s->hash, "MD5") == 0)
				call_md5(s->mssg);
			else if (ft_strcmp(s->hash, "SHA256") == 0)
				call_sha256(s->mssg);
			ft_putstr(" ");
			ft_putstr(av[i]);
			ft_putstr("\n");
		}
	}
	return (i);
}

int		read_file_q(t_struct *s, char **av, int i)
{
	int		j;
	int		fd;

	j = 0;
	fd = 0;
	i++;
	while (i < s->total_params)
	{
		if ((fd = open(av[i], O_RDONLY)) == EOF)
			print_error_not_file(s, av, i);
		else
		{
			fd = open(av[i], O_RDONLY);
			fd = read(fd, s->mssg, MAX);
			s->mssg[fd + 1] = '\0';
			if (ft_strcmp(s->hash, "MD5") == 0)
				call_md5(s->mssg);
			else if (ft_strcmp(s->hash, "SHA256") == 0)
				call_sha256(s->mssg);
		}
		ft_putstr("\n");
		i++;
	}
	return (i);
}
