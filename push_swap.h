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
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

void	swap(t_list *stack);
void	swap_both(t_list *stack_one, t_list *stack_two);
void	rotate(t_list *stack);
void	rotate_both(t_list *stack_one, t_list *stack_two);

t_list	*node_creation(int argc, char **argv);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		check_duplicates(t_list *stack_a);

#endif