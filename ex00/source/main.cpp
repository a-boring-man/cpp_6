/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2023/07/19 12:23:31 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

int	ft_is_char( string input ) {

	int len = input.length();
	if (len == 3 && input.at(0) == '\'' && input.at(2) == '\'')
		return (1);
	return (0);
}

int	ft_what_type( string input ) {

	const int	tbl[4][7] = {{1, -1, 1, 4, -1, -1, -1}, \
	{2, -1, -1, -1, -1, -1, -1}, {3, 5, 3, 3, 5, 5, -1}, \
	{-1, -1, -1, -1, 6, 6, -1}};
	int			cs = 0;

	for (size_t i = 0; cs > -1 && input.length() > i && input.at(i); i++)
	{
		if (input.at(i) == '.')
			cs = tbl[0][cs];
		else if (input.at(i) == '-')
			cs = tbl[1][cs];
		else if (input.at(i) >= '0' && input.at(i) <= '9')
			cs = tbl[2][cs];
		else if (input.at(i) == 'f')
			cs = tbl[3][cs];
		else
			cs = -1;
	}
	if (cs == 3)
		return (1);
	if (cs == 6 || !input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (2);
	if (cs == 4 || cs == 5 || !input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		return (3);
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
		if (!input.compare("nanf") || !input.compare("+inff") || !input.compare("-inff"))
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
		if (!input.compare("nan") || !input.compare("+inf") || !input.compare("-inf"))
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
		if (!input.compare("nanf") || !input.compare("+inff") || !input.compare("-inff"))
		{
			cout << "impossible" << endl;
			break;
		}
		fi = stof(input);
		if (static_cast<int>(fi) < INT_MIN || static_cast<int>(fi) > INT_MAX)
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
		if (!input.compare("nan") || !input.compare("+inf") || !input.compare("-inf"))
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
		cout.precision(9);
		cout << "float : " << static_cast<float>(input.at(1)) << endl;
		break;
	
	case 1: // int to float
		try
		{
			stoi(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
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
		cout.precision(9);
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
		cout.precision(9);
		if (!input.compare("nan") || !input.compare("nanf"))
		{
			cout << "base type : float : nanf" << endl;
			break;
		}
		else if (!input.compare("+inf") || !input.compare("+inff"))
		{
			cout << "base type : float : +inff" << endl;
			break;
		}
		else if (!input.compare("-inf") || !input.compare("-inff"))
		{
			cout << "base type : float : -inff" << endl;
			break;
		}
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
		if (!input.compare("nan") || !input.compare("nanf"))
		{
			cout << "float : nanf" << endl;
			break;
		}
		else if (!input.compare("+inf") || !input.compare("+inff"))
		{
			cout << "float : +inff" << endl;
			break;
		}
		else if (!input.compare("-inf") || !input.compare("-inff"))
		{
			cout << "flaot : -inff" << endl;
			break;
		}
		dtf = stod(input);
		if (dtf < -FLT_MAX || dtf > FLT_MAX)
		{
			cout << "impossible" << endl;
			break;
		}
		cout.precision(9);
		cout << "float : " << static_cast<float>(dtf) << endl;
		break;

	default:
		break;
	}
	return;
}

void	ft_display_double( int i, string input ) {

	int		id;
	float	fd;
	double	dd;
	switch (i)
	{
	case 0: // char to double
		cout.precision(17);
		cout << "double : " << static_cast<double>(input.at(1)) << endl;
		break;
	
	case 1: // int to double
		try
		{
			stoi(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		try
		{
			stod(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		id = stod(input);
		cout.precision(17);
		cout << "double : " << id << endl;
		break;

	case 2: // float to double
		try
		{
			stof(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		try
		{
			stod(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		if (!input.compare("nanf") || !input.compare("nan"))
		{
			cout << "double : nan" << endl;
			break;
		}
		else if (!input.compare("+inff") || !input.compare("+inf"))
		{
			cout << "double : +inf" << endl;
			break;
		}
		else if (!input.compare("-inff") || !input.compare("-inf"))
		{
			cout << "double : -inf" << endl;
			break;
		}
		fd = stod(input);
		cout.precision(17);
		cout << "double : " << static_cast<double>(fd) << endl;
		break;

	case 3: // double to double
		try
		{
			stod(input);
		}
		catch(const std::exception& e)
		{
			cout << "impossible" << endl;
			break;
		}
		if (!input.compare("nan") || !input.compare("nanf"))
		{
			cout << "base type : double : nan" << endl;
			break;
		}
		else if (!input.compare("+inf") || !input.compare("+inff"))
		{
			cout << "base type : double : +inf" << endl;
			break;
		}
		else if (!input.compare("-inf") || !input.compare("-inff"))
		{
			cout << "base type : double : -inf" << endl;
			break;
		}
		dd = stod(input);
		cout.precision(17);
		cout << "base type : double : " << dd << endl;
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

	string	input = av[1];
	bool	result[4] = {0, 0, 0, 0};
	int 	i = 0;

	result[0] = ft_is_char(input);
	if (ft_what_type(input))
		result[ft_what_type(input)] = 1;
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
	ft_display_double(i, input);

	return (0);
}
