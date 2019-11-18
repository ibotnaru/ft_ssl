/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:45:54 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/14 14:27:48 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		print_p(t_struct *s)
{
	if (s->open_flag == 0)
	{
		if (ft_strcmp(s->hash, "MD5") == 0)
		{
			if (s->p == 0)
				print_p_contin(s);
			else
				call_md5("");
		}
		else if (ft_strcmp(s->hash, "SHA256") == 0)
		{
			if (s->p == 0)
				print_p_contin(s);
			else
				call_sha256("");
		}
	}
	else
		ft_putstr(" -p: No such file or directory");
	ft_putstr("\n");
}

void		print_p_contin(t_struct *s)
{
	int fd;

	fd = read(0, s->mssg, 1024);
	s->p = 1;
	ft_putstr(s->mssg);
	call_md5(s->mssg);
}

int			print_q(t_struct *s, char **av, int i)
{
	check_if_file(s, av, i);
	if (s->open_flag == 1)
	{
		i = read_file_q(s, av, i);
		return (i);
	}
	else
	{
		check_s_if_exists(s, av, i);
		if (s->s == 1)
			return (i);
		else if (s->p == 1)
		{
			if (s->flag_repeat == 0)
			{
				s->flag_repeat = 1;
				print_null(s);
			}
		}
		else
			no_file_print_q(s);
	}
	return (i);
}

int			print_r(t_struct *s, char **av, int i)
{
	check_if_file(s, av, i);
	if (s->open_flag == 1)
	{
		i = read_file_r(s, av, i);
		return (i);
	}
	else
	{
		check_s_if_exists(s, av, i);
		if (s->s == 1)
			return (i);
		else if (s->p == 1)
		{
			if (s->flag_repeat == 0)
			{
				s->flag_repeat = 1;
				print_null(s);
			}
		}
		else
			no_file_print_r(s);
	}
	return (i);
}

int			print_s(t_struct *s, char *str, int i)
{
	if (s->q == 1)
		check_hash(s, str);
	else if (s->r == 1)
	{
		check_hash(s, str);
		ft_putstr(" \"");
		ft_putstr(str);
		ft_putstr("\"");
	}
	else
		print_str(s, str);
	ft_putstr("\n");
	return (i + 1);
}
