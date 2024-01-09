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
	MyVector<int> vec2;
	for (int i = 0; i < 7; ++i){
	
		vec.push_back(i);
		vec2.push_back(i + 5);
	}

	//std::cout << vec << std::endl;

	for (MyVector<int>::itr it = vec.begin(); it != vec.end(); ++it){
		
		std::cout << " " << *it ;
	}

	MyVector<int>::itr it = vec.begin();
	MyVector<int>::itr it2 = vec2.begin();
	std::cout << std::endl;
	std::cout << " it [3] = " << it[3] << std::endl;
	std::cout << " vec == vec2 = " << std::boolalpha << (vec == vec2) << std::endl;
	std::cout << std::endl;
}
