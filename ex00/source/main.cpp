/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/13 15:21:40 by jrinna           ###   ########lyon.fr   */
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
	if (cs > 6 || !input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
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
	if (cs > 4 || !input.compare("-inf") || !input.compare("+inf") || !input.compare("nan") )
		return (1);
	return (0);
}

void	ft_display_char(int i, string input) {

	int		ic;
	float	fc;
	float	dc;
	switch (i)
	{
	case 0: // if already char
		cout << "base type : char : '" << input.at(1) << "'" << endl;
		break;

	case 1: // if int to char
		try
		{
			stoi(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		ic = stoi(input);
		if ((ic > 31 && ic < 127) || (ic > 8 && ic < 14))
			cout << "char : '" << static_cast<char>(ic) << "'" << endl;
		else if (ic > 255 || ic < 0)
			cout << "impossible" << endl;
		else
			cout << "Non displayable" << endl;
		break;

	case 2: // if float to char
		try
		{
			stof(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		fc = stof(input);
		if ((fc > 31 && fc < 127) || (fc > 8 && fc < 14))
			cout << "char : '" << static_cast<char>(fc) << "'" << endl;
		else if (fc > 255 || fc < 0)
			cout << "impossible" << endl;
		else
			cout << "Non displayable" << endl;
		break;

	case 3: // if double to char
		try
		{
			stod(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		dc = stod(input);
		if ((dc > 31 && dc < 127) || (dc > 8 && dc < 14))
			cout << "char : '" << static_cast<char>(dc) << "'" << endl;
		else if (dc > 255 || dc < 0)
			cout << "impossible" << endl;
		else
			cout << "Non displayable" << endl;
		break;

	default:
		break;
	}
	return;
	
}

void	ft_display_int(int i, string input) {

	int		ii;
	float	fi;
	double	di;
	switch (i)
	{
	case 0: // char to int
		cout << "int : " << static_cast<int>(input.at(1)) << endl;
		break;
	
	case 1: // int to int
		try
		{
			stoi(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		ii = stoi(input);
		cout << "base type : int : " << ii << endl;
		break;

	case 2: // float to int
		try
		{
			stof(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		fi = stof(input);
		if (fi < INT_MIN || fi > INT_MAX)
		{
			cout << "impossible" << endl;
			break;
		}
		cout << "int : " << static_cast<int>(fi) << endl;
		break;

	case 3: // double to int
		try
		{
			stod(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		di = stod(input);
		if (di < -2147483648 || di > 2147483647)
		{
			cout << "impossible" << endl;
			break;
		}
		cout << "int : " << static_cast<int>(di) << endl;
		break;

	default:
		break;
	}
	return;
}

void	ft_display_float(int i, string input) {

	int		itf;
	float	ftf;
	double	dtf;
	switch (i)
	{
	case 0: // char to float
		cout << "float : " << static_cast<float>(input.at(1)) << endl;
		break;
	
	case 1: // int to float
		try
		{
			stof(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		itf = stof(input);
		cout << "float : " << itf << endl;
		break;

	case 2: // float to float
		try
		{
			stof(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		ftf = stof(input);
		cout << "base type : float : " << ftf << endl;
		break;

	case 3: // double to float
		try
		{
			stod(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		dtf = stod(input);
		if (dtf < -FLT_MAX || dtf > FLT_MAX)
		{
			cout << "impossible" << endl;
			break;
		}
		cout << "float : " << static_cast<float>(dtf) << endl;
		break;

	default:
		break;
	}
	return;
}

int main( int ac, char **av ) {

	if ( ac != 2  || !av[1][0] )
	{
		cout << "please use only one string as input" << endl;
		return (1);
	}

	int 	(* f [4])(string input) = {&ft_is_char, &ft_is_int, &ft_is_float, &ft_is_double};
	string	input = av[1];
	bool	result[4] = {0, 0, 0, 0};
	int 	i = 0;

	for (int i = 0; i < 4; i++)
	{
		if ( f[i]( input ) )
		{
			result[i] = 1;
		}
	}
	while (i < 4 && !result[i])
		i++;
	if (i == 4)
	{
		cout << "type is not recognize/supported" << endl;
		return (1);
	}
	ft_display_char(i, input);
	ft_display_int(i, input);
	ft_display_float(i, input);
	//ft_display_double(result, input);

	return (0);
}
