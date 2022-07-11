/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:15:59 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:38:29 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

int	*ft_parse_bonus(int argc, char **argv)
{
	int	*temp;
	int	i;

	i = 0;
	temp = (int *)malloc(sizeof(int) * argc - 1);
	if (!temp)
		return (0);
	while (i < argc - 1)
	{
		if (!ft_int_is_valid_bonus(argv[i + 1]))
		{
			free(temp);
			return (0);
		}
		temp[i] = ft_atoi(argv[i + 1]);
		if (ft_num_is_in_bonus(temp, i))
		{
			free(temp);
			return (0);
		}
		i++;
	}
	return (temp);
}

int	*ft_split_args_bonus(char *argv, int size)
{
	int	*temp;
	int	i;
	int	j;

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
			if (ft_num_is_in_bonus(temp, j))
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

int	ft_size_bonus(char *arg)
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

int	ft_num_is_in_bonus(int *temp, int i)
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

int	ft_int_is_valid_bonus(char *number)
{
	int i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}