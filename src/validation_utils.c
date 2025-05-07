#include "../includes/push_swap.h"

static int	is_valid_integer(char *str)
{
	size_t		i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || 
			(sign == 0 && result * sign < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_number(char *str)
{
	size_t		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (!is_valid_integer(str))
		return (0);
	return (1);
}

static int	*convert_data_to_int(char **data, size_t *elements)
{
	size_t	i;
	int		*nums;

	i = 0;
	while (data[i])
		i++;
	nums = (int *)malloc(sizeof(int) * i);
	if (!nums)
		return (NULL);
	*elements = i;
	return (nums);
}

static int	find_duplicate(int analized, int num, int *data)
{
	int	j;
	
	j = 0;
	while (j < analized)
	{
		if (num == data[j])
			return (1);
		j++;
	}
	return (0);
}

int	*process_numbers(char **data, size_t *elements)
{
	size_t	i;
	int		*nums;

	nums = convert_data_to_int(data, elements);
	if (!nums)
		return (NULL);
	i = 0;
	while (data[i])
	{
		if (!is_valid_number(data[i]))
		{
			free(nums);
			return (NULL);
		}
		nums[i] = ft_atoi(data[i]);
		if (find_duplicate(i, nums[i], nums))
		{
			free(nums);
			return (NULL);
		}
		i++;
	}
	return (nums);
}

