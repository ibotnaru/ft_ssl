/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:47:17 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/12 19:14:06 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	no_file_print_q(t_struct *s)
{
	int		fd;

	fd = read(0, s->mssg, MAX);
	if (ft_strcmp(s->hash, "SHA256") == 0)
		call_sha256(s->mssg);
	else if (ft_strcmp(s->hash, "MD5") == 0)
		call_md5(s->mssg);
	ft_putstr("\n");
}

void	no_file_print_r(t_struct *s)
{
	int		fd;

	fd = read(0, s->mssg, MAX);
	if (ft_strcmp(s->hash, "SHA256") == 0)
		call_sha256(s->mssg);
	else if (ft_strcmp(s->hash, "MD5") == 0)
		call_md5(s->mssg);
	ft_putstr(s->mssg);
	ft_putstr("\n");
}

void	print_error_not_file(t_struct *s, char **av, int i)
{
	ft_putstr(s->hash);
	ft_putstr(": ");
	ft_putstr(av[i]);
	ft_putstr(": ");
	ft_putstr("No such file or directory");
}

int		print_not_flag(t_struct *s, char **av, int i)
{
	int j;
	int fd;

	j = 0;
	fd = 0;
	while (i < s->total_params)
	{
		if ((fd = open(av[i], O_RDONLY)) == EOF)
			print_error_not_file(s, av, i);
		else
		{
			fd = open(av[i], O_RDONLY);
			fd = read(fd, s->mssg, 1024);
			s->mssg[fd] = '\0';
			call_hash_func(s, av, i);
		}
		ft_putstr("\n");
		i++;
	}
	return (i);
}
