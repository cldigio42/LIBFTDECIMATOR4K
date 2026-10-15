/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cldi-gio <cldi-gio@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 03:58:51 by cldi-gio          #+#    #+#             */
/*   Updated: 2026/10/14 04:18:16 by cldi-gio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define MIN_INT -2147483648
# define STR_MIN_INT "-2147483648"
# define MAX_INT 2147483647
# define STR_MAX_INT "2147483647"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *nptr);
unsigned int	ft_lstsize(t_list *lst);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
void			ft_bzero(void *s, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t size);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));

#endif
