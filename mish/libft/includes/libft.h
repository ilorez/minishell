/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:06:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 10:49:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef FT_EXEC_NAME
#  define FT_EXEC_NAME "mish"
# endif
// includes
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

// local libs
# include "ft_linked_lst.h"
# include "ft_malloc.h"
# include "get_next_line.h"
# include "t_arr.h"
# include "t_bool.h"
# include "t_errno.h"
# include "t_str.h"

// memory functions
void		*ft_memset(void *b, int c, size_t len);
// this function is for setting a memory block to a specific value
void		ft_bzero(void *s, size_t n);
// this function is for setting a memory block to zero
void		*ft_memcpy(void *dst, const void *src, size_t n);
// this function is for copying a memory block to another memory block
void		*ft_memmove(void *dst, const void *src, size_t len);
// this function is for copying a memory block to another memory block
void		*ft_memchr(const void *s, int c, size_t n);
// this function is for searching for a character in a memory block
int			ft_memcmp(const void *s1, const void *s2, size_t n);
// this function is for comparing two memory blocks
void		*ft_calloc(size_t count, size_t size);
// this function is for allocating memory and setting it to zero
void		*ft_free_str_lst(char **strs);

// string functions
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
// this function is for searching for a substring in a string
int			ft_strncmp(const char *s1, const char *s2, size_t n);
// this function is for comparing two strings
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
// this function is for copying a string to another string
size_t		ft_strlcat(char *dst, const char *src, size_t size);
// the difference between strlcat and strlcpy is that strlcat
// append the src to dst and strlcpy copy the src to dst
char		*ft_strdup(const char *s1);
char		*ft_strndup(char const *s, size_t len);
// this function is for duplicating a string
char		*ft_substr(char const *s, unsigned int start, size_t len);
// this function is for extracting a substring from a string
char		*ft_strtrim(char const *s1, char const *set);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strupcase(char *str);
char		*ft_strlowcase(char *str);
char		*ft_strjoin_list(char const **arr, char const *sep);

// is functions
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_is_str_chars_same(char *str, char c);
int			ft_is_valid_num(char *str);
int			ft_isvalid_id(char *id);

// atoi & itoa functions
int			ft_atoi(const char *nptr);
long long	ft_atol(const char *nptr);
char		*ft_itoa(int n);
double		ft_strtod(const char *nptr, char **endptr);

// to functions
int			ft_toupper(int c);
int			ft_tolower(int c);

// put functions
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_print_str_arr(char **arr);

// arrays functions
char		*ft_strjoin(char const *s1, char const *s2, char const *c);
char		**ft_split(char const *s, char c);
char		**ft_split_cond(char const *s, int (f)(int));

#endif
