/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:35:00 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/12 19:14:21 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void				check_if_file(t_struct *s, char **av, int i)
{
	int		fd;
	int		tmp;
	char	str[1024];

	while (i < s->total_params)
	{
		fd = open(av[i], O_RDONLY);
		tmp = read(fd, str, 1024);
		if (tmp >= 1)
		{
			s->open_flag = 1;
			break ;
		}
		i++;
	}
}

int					check_if_p_exists(t_struct *s, char **av, int i, int p_fl)
{
	while (i < s->total_params)
	{
		if (ft_strcmp(av[i], "-p") == 0)
		{
			p_fl = 1;
			break ;
		}
		i++;
	}
	return (p_fl);
}

void				check_if_q_exists(t_struct *s, char **av, int i)
{
	while (i < s->total_params)
	{
		if (ft_strcmp(av[i], "-q") == 0)
		{
			s->q = 1;
			break ;
		}
		i++;
	}
}

void				check_s_if_exists(t_struct *s, char **av, int i)
{
	while (i < s->total_params)
	{
		if (ft_strcmp(av[i], "-s") == 0)
		{
			s->s = 1;
			break ;
		}
		i++;
	}
}
