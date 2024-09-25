#include "push_swap.h"

t_list *node_creation(int argc, char **argv)
{
	t_list		*new_stack;
	t_list		*temp;
	long long	content;
	int			i;
	int			j;
	int			sign;
	char		*atoi_str;
	int			length;

	i = 1;
	new_stack = NULL;
	temp = NULL;
	length = 0;
	j = 0;
	while (i < argc)
	{
		while(argv[i][j] != '+' && argv[i][j] != '-' && !ft_isdigit(argv[i][j]))
			j = j + 1; // Skip all the whitespaces beginning, middle and end
		sign = 1;
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			j += 1;
			length += 1;
		}
		while (ft_isdigit(argv[i][j]))
		{
			length = length + 1;
			if (length > 10)
			{
				ft_lstclear(&new_stack);
				return (NULL);
			}
			j += 1;
		}
		atoi_str = ft_substr(argv[i], j - length, length);
		content = sign * ft_atoi(atoi_str);
		if (content < INT_MIN || content > INT_MAX)
		{
			ft_lstclear(&new_stack);
			return (NULL);
		}
		else
		{
			if (new_stack == NULL)
			{
				new_stack = ft_lstnew(content); 
				if (new_stack == NULL) // malloc failed
					return (NULL);
			}
			else
			{
				temp = ft_lstnew(content);
				if (temp == NULL) // malloc failed
				{
					ft_lstclear(&new_stack);
					return (NULL);
				}
				ft_lstadd_back(&new_stack, temp);
			}
		}
		if (argv[i][j] >= 9 && argv[i][j] <= 32)
			length = 0;
		else if (argv[i][j] == '\0')
		{
			length = 0;
			j = 0;
			i = i + 1; // Move to the next element if we finished this current string
		}
	}
	return (new_stack);
}