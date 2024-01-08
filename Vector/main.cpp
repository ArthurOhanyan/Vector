#include <iostream>
#include <climits>
#include "prototype.h"

int main ()
{

	//MyVector<bool> b_vec;
	//MyVector<bool> vec;
	
	/*for (int i = 0; i < 10; ++i){
		
		b_vec.push_back(true);

	}*/
	//b_vec.print();
	/*for (int i = 0; i < 10; ++i){
		
		vec.push_back(false);

	}
	vec.print();
	std::cout << std::endl;
	MyVector<bool> vec(vec);
	std::cout << " print vec2 " << std::endl;
	vec2.print();*/

	MyVector<int> vec;
	for (int i = 0; i < 7; ++i){
	
		vec.push_back(i);
	}

	//std::cout << vec << std::endl;

	for (MyVector<int>::itr it = vec.begin(); it != vec.end(); ++it){
		
		std::cout << " " << *it ;
	}
	std::cout << std::endl;
}
