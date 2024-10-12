/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:15:00 by nkunnath          #+#    #+#             */
/*   Updated: 2024/09/26 10:15:01 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_space(char *input, int index)
{
	int	j;
	int	length;

	j = index;
	length = ft_strlen(input);
	while (j < length)
	{
		if (!is_space(input[j]))
			return (j);
		j += 1;
	}
	return (j);
}

static int	check_next_char(char *input, int index)
{
	if ((input[index] == '\0') || !ft_isdigit(input[index]))
		return (0);
	return (1);
}

static int	is_valid(int j, char *input, int length)
{
	while (j < length)
	{
		if (!ft_isdigit(input[j]))
		{
			if (input[j] != '+' && input[j] != '-' && !(is_space(input[j])))
				return (0);
			else if (is_space(input[j]))
				j = skip_space(input, j) - 1;
			else if (input[j] == '-' || input[j] == '+')
			{
				if (j != 0 && !is_space(input[j - 1]))
					return (0);
				else if (check_next_char(input, j + 1) == 0)
					return (0);
			}
		}
		j = j + 1;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	int		i;
	int		j;
	int		length;
	char	*input;

	i = 1;
	while (i < argc)
	{
		input = argv[i];
		j = skip_space(input, 0);
		length = ft_strlen(input);
		if (length == 0 || j == length)
			return (0);
		if (!is_valid(j, input, length))
			return (0);
		else
			i = i + 1;
	}
	return (1);
}
