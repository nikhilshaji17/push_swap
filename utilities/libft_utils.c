/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:36:33 by nkunnath          #+#    #+#             */
/*   Updated: 2024/09/26 12:36:35 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	answer;

	i = 0;
	sign = 1;
	answer = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || (str[i] >= 9 && str[i] <= 13))
			i = i + 1;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			i = i + 1;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			answer = (answer * 10) + (str[i] - 48);
			i = i + 1;
		}
		return (sign * answer);
	}
	return (sign * answer);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_space(int c)
{
	if (c >= 9 && c <= 32)
		return (1);
	return (0);
}
