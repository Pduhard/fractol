/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:26:54 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 19:02:13 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "ft_printf.h"
# define BUFF_SIZE 42

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_mfd
{
	struct s_mfd	*next;
	int				fd;
	char			*str;
}					t_mfd;

void				ft_putchar(char c);
void				ft_putstr(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, int nb);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strichr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
char				*ft_strfillnew(char c, int len);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strfsub(char **s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, char const *s2);
char				*ft_strfjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_ltoa(long n, char **array);
int					ft_lltoa(long long n, char **array);
int					ft_ldtoa(long double n, char **array, int prec);
void				round_float(char **nb, int prec);
int					ft_imttoa(intmax_t n, char **array);
int					ft_ulltoa(unsigned long long n, char **array);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new_el);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_countparts(char del, char const *str);
int					ft_pow(int n, int pow);
int					ft_sqrt(int n, int return_max);
void				*ft_memrcpy(void *dst, void *src, size_t n);
char				*ft_emptystr(void);
char				*ft_baseconvert(char *base, unsigned long long n);
int					get_next_line(const int fd, char **line);
int					ft_ifree(void **ptr, int i);
void				ft_swap(int *a, int *b);
int					ft_abs(int val);
double				ft_fabs(double val);

#endif
