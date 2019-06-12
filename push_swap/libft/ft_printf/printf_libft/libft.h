/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:57:15 by myener            #+#    #+#             */
/*   Updated: 2019/04/25 17:10:14 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 4096
# define MAX_FD 8192

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_abs(int nb);
int				ft_atoi(const char *str);
long long int	ft_atoll(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_intlen(long long int n);
int				ft_uintlen(unsigned long long int n);
int				ft_octlen(unsigned long long int n);
int				ft_hexlen(unsigned long long int n);
char			ft_itoc(int n);
char			*ft_lltoa(long long int n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putnbr_base(long long int nb, const char *base);
void			ft_putunbr_base(unsigned long long int nb, const char *base);
void			ft_putstr(char *str);
void			ft_putnbr_long(long long int nb);
void			ft_putunbr_long(unsigned long long int nb);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strsub(const char *s, unsigned int start, size_t len);

#endif
