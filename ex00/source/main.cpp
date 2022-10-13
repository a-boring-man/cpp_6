/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/13 09:57:44 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

int	ft_is_char( string input ) {

	int len = input.length();
	if (len == 3 && input.at(0) == '\'' && input.at(2) == '\'')
		return (1);
	return (0);
}

int	ft_is_int( string input ){

	const int	tbl[3][5] = {{1, -1, -1, -1, -1}, {2, 4, 4, -1, 4}, {3, 4, 4, -1, 4}};
	int			cs = 0;

	for (size_t i = 0; cs > -1 && input.length() > i && input.at(i); i++)
	{
		if (input.at(i) == '-')
			cs = tbl[0][cs];
		else if (input.at(i) >= '1' && input.at(i) <= '9')
			cs = tbl[1][cs];
		else if (input.at(i) == '0')
			cs = tbl[2][cs];
		else
			cs = -1;
	}
	if (cs > 1)
		return (1);
	return (0);
}

int	ft_is_float( string input ){

	const int	tbl[5][8] = {{1, -1, 1, 6, 6, -1, -1, -1}, \
	{2, -1, -1, -1, -1, -1, -1, -1}, {3, 5, 3, 3, -1, 5, 5, -1}, \
	{4, 5, 4, 3, -1, 5, 5, -1}, {5, -1, -1, -1, -1, 7, 7, -1}};
	int			cs = 0;

	for (size_t i = 0; cs > -1 && input.length() > i && input.at(i); i++)
	{
		if (input.at(i) == '.')
			cs = tbl[0][cs];
		else if (input.at(i) == '-')
			cs = tbl[1][cs];
		else if (input.at(i) >= '1' && input.at(i) <= '9')
			cs = tbl[2][cs];
		else if (input.at(i) == '0')
			cs = tbl[3][cs];
		else if (input.at(i) == 'f')
			cs = tbl[4][cs];
		else
			cs = -1;
	}
	if (cs > 6)
		return (1);
	return (0);
}

int	ft_is_double( string input ){

	const int	tbl[4][7] = {{1, -1, 1, 6, 6, -1, -1}, \
	{2, -1, -1, -1, -1, -1, -1}, {3, 5, 3, 3, -1, 5, 5}, \
	{4, 5, 4, 3, -1, 5, 5}};
	int			cs = 0;

	for (size_t i = 0; cs > -1 && input.length() > i && input.at(i); i++)
	{
		if (input.at(i) == '.')
			cs = tbl[0][cs];
		else if (input.at(i) == '-')
			cs = tbl[1][cs];
		else if (input.at(i) >= '1' && input.at(i) <= '9')
			cs = tbl[2][cs];
		else if (input.at(i) == '0')
			cs = tbl[3][cs];
		else
			cs = -1;
	}
	if (cs > 4)
		return (1);
	return (0);
}

int main( int ac, char **av ) {

	if ( ac != 2  || !av[1][0] )
	{
		cout << "please use only one string as input" << endl;
		return (1);
	}
	int (* f [4])(string input) = {&ft_is_char, &ft_is_int, &ft_is_float, &ft_is_double};
	string	input = av[1];
	bool	result[4] = {0, 0, 0, 0};
	for (int i = 0; i < 4; i++)
	{
		if ( f[i]( input ) )
		{
			result[i] = 1;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << endl;
	}

	return (0);
}