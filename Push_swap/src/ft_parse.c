/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:03:42 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/26 18:04:48 by crigonza         ###   ########.fr       */
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
		if (ft_num_is_in(temp, i) || !ft_check_int(ft_atoi(argv[i + 1])))
		{
			free(temp);
			return (0);
		}
		i++;
	}
	return (temp);
}

int	*ft_parse_2(int argc, char **argv)
{
	int	*temp;
	int	i;

	i = 0;
	temp = (int *)malloc(sizeof(int) * argc);
	if (!temp)
		return (0);
	while (i < argc)
	{
		if (!ft_int_is_valid(argv[i]))
		{
			free(temp);
			return (0);
		}
		temp[i] = ft_atoi(argv[i]);
		if (ft_num_is_in(temp, i) || !ft_check_int(ft_atoi(argv[i])))
		{
			free(temp);
			return (0);
		}
		i++;
	}
	return (temp);
}