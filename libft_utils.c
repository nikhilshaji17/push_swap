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

#include "push_swap.h"

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

static void	make_substr(char *sub, char	*s, unsigned int start, size_t len)
{
	unsigned int	sub_index;

	sub_index = 0;
	while (s[start] != '\0' && sub_index < (unsigned int)len)
	{
		sub[sub_index] = s[start];
		start = start + 1;
		sub_index = sub_index + 1;
	}
	sub[sub_index] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			length;

	substr = NULL;
	length = 0;
	if (s == NULL || ft_strlen(s) <= start)
	{
		substr = (char *)malloc(1);
		if (substr == NULL)
			return (substr);
		substr[0] = '\0';
		return (substr);
	}
	length = ft_strlen(s);
	if (length - start < len)
		len = length - start;
	substr = (char *)malloc((sizeof(char) * len) + 1);
	if (substr == NULL)
		return (substr);
	make_substr(substr, (char *)s, start, len);
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter += 1;
	}
	return (counter);
}
