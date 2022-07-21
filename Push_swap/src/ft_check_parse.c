/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:04:07 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/20 20:47:15 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*ft_parse(int argc, char **argv)
{
	int	*temp;
	int	i;

	i = 0;
	temp = (int *)malloc(sizeof(int) * argc - 1);
	if (!temp)
		return (0);
	while (i < argc - 1)
	{
		if (!ft_int_is_valid(argv[i + 1]))
		{
			free(temp);
			return (0);
		}
		temp[i] = ft_atoi(argv[i + 1]);
		if (ft_num_is_in(temp, i) || !ft_check_one(ft_atoi(argv[i + 1])))
		{
			free(temp);
			return (0);
		}
		i++;
	}
	return (temp);
}

int	*ft_split_args(char *argv, int size)
{
	int	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = (int *)malloc(sizeof(int) * size);
	if (!temp)
		return (0);
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ' || i == 0)
		{
			temp[j] = ft_atoi(&argv[i]);
			if (ft_num_is_in(temp, j) || !ft_check_one(ft_atoi(&argv[i])))
			{
				free(temp);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (temp);
}

int	ft_size(char *arg)
{
	int	size;
	int	i;

	i = 0;
	if (arg[0] != ' ')
		size = 1;
	else
		size = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ' && arg[i + 1] != '\0')
			size++;
		i++;
	}
	return (size);
}

int	ft_num_is_in(int *temp, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (temp[j] == temp[i])
			return (1);
		j++;
	}
	return (0);
}

int	ft_int_is_valid(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	if (number[i] == '\0')
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while(str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] == ' ')
			return (0);
		while(str[i] != ' ')
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}
