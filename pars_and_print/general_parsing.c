/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:40:28 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/14 14:26:46 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	call_hash_func(t_struct *s, char **av, int i)
{
	if (s->q == 1)
	{
		if (ft_strcmp(s->hash, "MD5") == 0)
			call_md5(s->mssg);
		else if (ft_strcmp(s->hash, "SHA256") == 0)
			call_sha256(s->mssg);
	}
	else if (s->r == 1)
	{
		if (ft_strcmp(s->hash, "MD5") == 0)
			call_md5(s->mssg);
		else if (ft_strcmp(s->hash, "SHA256") == 0)
			call_sha256(s->mssg);
		ft_putstr(" ");
		ft_putstr(av[i]);
	}
	else
		print_file_md5_sha256(s, av, i);
}

void	parsing_flags(char **av, t_struct *s)
{
	int		i;
	int		p_fl;

	i = 1;
	p_fl = 0;
	while (++i < s->total_params)
	{
		if (s_check(s, av, i))
			i = print_s(s, av[i + 1], i);
		else if (p_check(av, i))
			print_p(s);
		else if (q_check(s, av, i))
		{
			if (parsing_3(av, s, &i, &p_fl))
				continue ;
		}
		else if (r_check(s, av, i))
		{
			if (parsing_2(av, s, &i, &p_fl))
				continue ;
		}
		else if (not_flag(av, i))
			i = print_not_flag(s, av, i);
	}
}

int		parsing_2(char **av, t_struct *s, int *i, int *p_fl)
{
	check_if_q_exists(s, av, *i);
	*p_fl = check_if_p_exists(s, av, *i, *p_fl);
	if (*p_fl == 1)
		return (1);
	else if (s->q == 0)
		*i = print_r(s, av, *i);
	return (0);
}

int		parsing_3(char **av, t_struct *s, int *i, int *p_fl)
{
	*p_fl = check_if_p_exists(s, av, *i, *p_fl);
	if (*p_fl == 1)
		return (1);
	else
		*i = print_q(s, av, *i);
	return (0);
}

int		not_flag(char **av, int i)
{
	int j;

	j = 0;
	if (av[i][j] == '-')
	{
		if (av[i][j + 1] != 's' && av[i][j + 1] != 'p' &&
				av[i][j + 1] != 'q' && av[i][j + 1] != 'r')
		{
			ft_putstr("illegal option -- ");
			ft_putstr(&av[i][j + 1]);
			ft_putstr("\nusage: [-pqr] [-s string] [files]\n");
			exit(1);
		}
		else
			return (0);
	}
	else if (av[i][0] != '-')
		return (1);
	else
		return (0);
}
