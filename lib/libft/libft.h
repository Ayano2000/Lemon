/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:45:33 by ayano             #+#    #+#             */
/*   Updated: 2019/09/09 15:27:22 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define INTMAX 2147483647
# define INTMIN -2147483648
# define BUFF_SIZE 1
# define MININT "-2147483648"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

double				ft_atod(const char *str);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strchr(const char *str, int to_find);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strdup(const char *str1);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle \
																, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncat(char *str1, const char *str2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strrchr(const char *str, int to_find);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strcpy(char *dest, const char *src);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *str, int fd);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **to_free);
char				*ft_strnew(size_t size);
void				ft_strdel(char **stf);
void				ft_strclr(char *str);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int					ft_strequ(char const *str1, char const *str2);
int					ft_strnequ(char const *str1, char const *str2, size_t n);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *str1, char const *str2);
char				*ft_strtrim(char const *str);
char				**ft_strsplit(char const *str, char c);
int					ft_intlen(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);

#endif
