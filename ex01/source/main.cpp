/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2023/07/19 12:20:37 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

__intptr_t serialize(Data* ptr) {

	return (reinterpret_cast<__intptr_t>(ptr));
}

Data* deserialize(__intptr_t raw) {

	return (reinterpret_cast<Data*>(raw));
}

int main( void ) {

	Data 		D;
	__intptr_t	P;
	P = serialize(&D);
	cout << &D << endl << D.a << endl << D.b << endl;
	//cout << P << endl;
	cout << deserialize(P) << endl << deserialize(P)->a << endl << deserialize(P)->b << endl;
	return (0);
}
