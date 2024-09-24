#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

long long		ft_atoi(const char *str);
int		ft_isdigit(int c);
t_list	*node_creation(int argc, char **argv);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_strlen(const char *str);

#endif