/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/14 15:09:51 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"
#include <ctime>

class	Base {
	public :
	virtual ~Base(){};
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base*	generate ( void ) {

	srand(time(NULL));
	int i = rand();
	if ( i % 3 == 1 )
	{
		return (new A);
	}
	else if ( i % 3 == 2 )
	{
		return (new B);
	}
	else
	{
		return (new C);
	}
}

void	identify( Base* p ) {

	A*	A_ptr = dynamic_cast<A*>(p);
	B*	B_ptr = dynamic_cast<B*>(p);
	C*	C_ptr = dynamic_cast<C*>(p);
	if (A_ptr)
		cout << "p is an A" << endl;
	if (B_ptr)
		cout << "p is an B" << endl;
	if (C_ptr)
		cout << "p is an C" << endl;
	return;
}

void	identify( Base& p ) {

	try
	{
		A&	A_ptr = dynamic_cast<A&>(p);
		(void)A_ptr;
	}
	catch(const std::exception& e)
	{
		cout << "p is not an A" << endl;
	}
	try
	{
		B&	B_ptr = dynamic_cast<B&>(p);
		(void)B_ptr;
	}
	catch(const std::exception& e)
	{
		cout << "p is not an B" << endl;
	}
	try
	{
		C&	C_ptr = dynamic_cast<C&>(p);
		(void)C_ptr;
	}
	catch(const std::exception& e)
	{
		cout << "p is not an C" << endl;
	}
	
	return;
}

int main( void ) {

	Base*	R = generate();
	Base&	RR = *R;
	identify(R);
	identify(RR);

	return (0);
}
