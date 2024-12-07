/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:24:19 by nkunnath          #+#    #+#             */
/*   Updated: 2024/09/26 12:24:20 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	long long	make_str(char *input, int *j, int str_len)
{
	char				*atoi_str;
	long long			answer;

	atoi_str = ft_substr(input, *j - str_len, str_len);
	if (atoi_str == NULL)
		return (-2147483649);
	answer = ft_atoi(atoi_str);
	free(atoi_str);
	return (answer);
}

static long long	verify_input(char *input, int *j)
{
	int					str_length;
	int					sign;
	long long			content;

	str_length = 0;
	while (is_space(input[*j]))
		*j = *j + 1;
	sign = 1;
	if (input[*j] == '-' || input[*j] == '+')
	{
		*j += 1;
		str_length += 1;
		if (input[*j] == '-')
			sign = -1;
	}
	while (ft_isdigit(input[*j]))
	{
		str_length = str_length + 1;
		if (str_length > 11)
			return (-2147483649);
		*j += 1;
	}
	content = sign * make_str(input, j, str_length);
	return (content);
}

static int	check_end(char *input, int i, int *j)
{
	while (is_space(input[*j]))
		(*j)++;
	if (input[*j] == 0)
	{
		*j = 0;
		return (i + 1);
	}
	return (i);
}

t_list	*node_creation(int argc, char **argv)
{
	t_list		*new_stack;
	t_list		*temp;
	long long	content;
	int			i;
	int			j;

	i = 1;
	new_stack = NULL;
	temp = NULL;
	j = 0;
	while (i < argc)
	{
		content = verify_input(argv[i], &j);
		if (content < INT_MIN || content > INT_MAX)
			return (ft_lstclear(&new_stack), NULL);
		temp = ft_lstnew(content);
		if (temp == NULL)
			return (ft_lstclear(&new_stack), NULL);
		ft_lstadd_back(&new_stack, temp);
		i = check_end(argv[i], i, &j);
	}
	return (new_stack);
}
