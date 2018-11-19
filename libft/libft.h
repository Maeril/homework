/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:57:15 by myener            #+#    #+#             */
/*   Updated: 2018/11/19 18:25:20 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <xlocale.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int             ft_isalnum(int c);
int		ft_isalpha(int c);
int             ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void    *ft_memalloc(size_t size);
void    ft_memdel(void **ap);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		*ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memset(void *b, int c, size_t len);
void    ft_putchar(char c);
void	ft_putnbr(int nb);
void	*ft_putstr(char *str);
char	*ft_strcat(char *src, const char *dest);
char    *ft_strchr(const char *s, int c);
void    ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(const char *src, char *dest);
void    ft_strdel(char **as);
char	*ft_strdup(const char *str);
int     ft_strequ(char const *s1, char const *s2);
void    ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	*ft_strlcat(char *src, const char *dest, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strmap(char const *s, char (*f)(char));
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *src, const char *dest, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(const char *src, char *dest, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char    *ft_strnew(size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_strrchr(const char *s, int c);
char	*ft_strrev(char *str);
char	*ft_strstr(const char *str, const char *find);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
int		ft_tolower(int c);
int		ft_toupper(int c);


#endif
