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
