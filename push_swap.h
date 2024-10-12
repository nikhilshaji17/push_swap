/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:17:04 by nkunnath          #+#    #+#             */
/*   Updated: 2024/09/26 12:17:06 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

int				check_duplicates(t_list *stack_a);
int				check_input(int argc, char **argv);
long long		ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
int				is_space(int c);

void			sort_stacks(t_list **stack_a, t_list **stack_b);

void			swap_a(t_list *stack_a);
void			swap_b(t_list *stack_b);
void			swap_both(t_list *stack_a, t_list *stack_b);
void			push_a(t_list **stack_a, t_list **stack_b);
void			push_b(t_list **stack_a, t_list **stack_b);
void			rev_rotate_a(t_list **stack_a);
void			rev_rotate_b(t_list **stack_b);
void			rev_rotate_both(t_list **stack_a, t_list **stack_b);
void			rotate_a(t_list *stack_a);
void			rotate_b(t_list *stack_b);
void			rotate_both(t_list *stack_a, t_list *stack_b);

t_list			*node_creation(int argc, char **argv);
t_list			*ft_lstnew(int content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);
void			ft_lstdelone(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);

#endif
