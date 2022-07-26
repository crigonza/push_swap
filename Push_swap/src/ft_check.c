/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:04:07 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/26 18:06:08 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*ft_split_args(char *argv, int size)
{
	int i;

	i = 0;
	int	*nbarray;
	char	**temp;
	temp = ft_split(argv, ' ');
	nbarray = ft_parse_2(size, temp);
	while (temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(temp);
	return(nbarray);
}

int	ft_size(char *arg)
{
	int	size;
	int	i;

	i = 0;
	if (arg[0] != ' ' && arg[0] != '\0')
		size = 1;
	else
		size = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ' && arg[i + 1] != '\0' && arg[i + 1] != ' ')
			size++;
		i++;
	}
	if (size == 1 && (!ft_check_int(ft_atoi(arg)) || !ft_int_is_valid(arg)))
		ft_error();
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
		return(0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_check_int(long int num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		return (0);
	}
	return (1);
}
