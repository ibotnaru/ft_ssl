/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psqr_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:55 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/14 14:38:29 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	check_hash(t_struct *s, char *str)
{
	if (ft_strcmp(s->hash, "MD5") == 0)
		call_md5(str);
	else if (ft_strcmp(s->hash, "SHA256") == 0)
		call_sha256(str);
}

int		p_check(char **av, int current)
{
	if (ft_strcmp(av[current], "-p") == 0)
		return (1);
	else
		return (0);
}

int		q_check(t_struct *s, char **av, int current)
{
	if (ft_strcmp(av[current], "-q") == 0)
	{
		s->q = 1;
		return (1);
	}
	else
		return (0);
}

int		s_check(t_struct *s, char **av, int current)
{
	if (ft_strcmp(av[current], "-s") == 0)
	{
		s->s = 1;
		if (current == s->total_params - 1)
		{
			printf("option requires an argument -- s\n");
			printf("usage: [-pqr] [-s string] [files ...]\n");
			return (0);
		}
		else
			return (1);
	}
	return (0);
}

int		r_check(t_struct *s, char **av, int current)
{
	if (ft_strcmp(av[current], "-r") == 0)
	{
		s->r = 1;
		return (1);
	}
	else
		return (0);
}
