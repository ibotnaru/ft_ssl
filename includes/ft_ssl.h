/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:55:10 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/11/12 19:15:36 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <unistd.h>
# include "../libft/libft.h"
# include "md5.h"
# include "sha256.h"

# define MAX 100000

/*
** Defining the ERROR messages
*/

# define ERR_USG "usage: ./ft_ssl [command][command opts][command args]\n"
# define ERR_HASH "error: invalid command; usage: [md5] or [sha256]\n"

/*
** Main struct
*/

typedef struct			s_struct
{
	char				*hash;
	int					invld_flag;
	int					open_flag;
	int					flag;
	int					flag_repeat;
	int					s;
	int					p;
	int					q;
	int					r;
	int					i;
	int					total_params;
	char				mssg[1024];
}						t_struct;

/*
** Parsing functions
*/

void					parsing_hash(t_struct *strct, char **av);
void					parsing_flags(char **av, t_struct *s);
int						parsing_2(char **av, t_struct *s, int *i, int *p_fl);
int						parsing_3(char **av, t_struct *s, int *i, int *p_fl);
void					check_hash(t_struct *s, char *str);
int						s_check(t_struct *s, char **av, int current);
int						p_check(char **av, int current);
int						q_check(t_struct *s, char **av, int current);
int						r_check(t_struct *s, char **av, int current);
void					check_s_if_exists(t_struct *s, char **av, int i);
int						check_if_p_exists(t_struct *s, char **av,
							int i, int p_fl);
void					check_if_q_exists(t_struct *s, char **av, int i);
int						s_check(t_struct *s, char **av, int current);
void					check_if_file(t_struct *s, char **av, int i);
int						read_file_r(t_struct *s, char **av, int i);
int						read_file_q(t_struct *s, char **av, int i);
int						not_flag(char **av, int i);

/*
** General printing functns
*/

int						print_s(t_struct *s, char *str, int i);
void					print_p(t_struct *s);
void					print_p_contin(t_struct *s);
int						print_q(t_struct *s, char **av, int i);
int						print_r(t_struct *s, char **av, int i);
void					print_str(t_struct *s, char *str);
int						print_not_flag(t_struct *s, char **av, int i);
void					print_null(t_struct *s);
void					print_error_not_file(t_struct *s, char **av, int i);
void					no_file_print_q(t_struct *s);
void					no_file_print_r(t_struct *s);
void					print_file_md5_sha256(t_struct *s, char **av, int i);

/*
** Hashing functions
** (the rest of them are in "ft_md5.h" and "ft_sha256.h")
*/

void					call_md5(char *str);
void					call_sha256(char *str);
void					call_hash_func(t_struct *s, char **av, int i);

#endif
