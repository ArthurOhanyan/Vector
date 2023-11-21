#include <iostream>
#include <climits>
template <typename T>
class MyVector
{
	T* v_ptr;
	int v_size;
	int v_capacity;
	void reallocator (int x = 0){
			
		x == 0 ? v_capacity *= 2 : v_capacity = x;
		T* tmp = new T [v_capacity];
		for (int i = 0; i < v_size; ++i){
			
			tmp [i] = v_ptr[i];
		}	
		delete [] v_ptr;
		v_ptr = tmp;
		tmp = nullptr;
	}

	public:
	MyVector () {
		
		v_ptr = nullptr;
		v_size = 0;
		v_capacity = 0;
	}

	~ MyVector () {
		
		if (v_ptr){
			
			delete [] v_ptr;
			v_ptr = nullptr;
		}
		v_size = 0;
		v_capacity = 0;
	}	

	int size ();
	size_t max_size ();
	void resize (int);
	size_t capacity ();
	bool empty ();
	void reserv (int);
	void shrink_to_fit();
	void push_back();

	
	  std::ostream& operator << (std::ostream& os)
	{
		for (int i = 0; i < v_size; ++i){
			
			os << v_ptr[i] << " ";
		}

		return os;
		
	}
	

	
};

template <typename T>
std::ostream& operator << (std::ostream& os, MyVector<T>& vec){

	return vec.operator<<(os);

}


int main ()
{
	MyVector<int> my_vec;
	std::cout << " the size is : " << my_vec.size() << std::endl;
	std::cout << " the max size is : " << my_vec.max_size() << std::endl;
	my_vec.resize (5);
	std::cout << " the size after resize is : " << my_vec.size() << std::endl;
	std::cout << " The capacity is :: " << my_vec.capacity() << std::endl;
	std::cout << std::boolalpha << " my_vec.empty () :: " << my_vec.empty() << std::endl;
        my_vec.reserv (15);
	std::cout << std::endl;
        std::cout << " after reserv capacity () :: " << my_vec.capacity () << std::endl;	
	my_vec.shrink_to_fit();
	std::cout << " after shrink to fit capacity is :: " << my_vec.capacity() << std::endl;
	std::cout << my_vec ;

}
template <typename T>
MyVector::MyVector<T>(const Vector& obj)
{
	
	
}

template <typename T>
int MyVector<T>::size()
{
	return v_size;
}

template <typename T>
size_t MyVector<T>::max_size ()
{
	return LONG_MAX;
}

template <typename T>
void MyVector<T>::resize (int new_size)
{
	if (!v_ptr){
		
		std::cout << " resize() function -> nullptr :: error " << std::endl;
	//	exit(0);
	}

	if (new_size > v_capacity){
		
		MyVector<T>::reallocator(new_size);

	}
       
	if (new_size < v_size){
		
		v_size = new_size;

	} else if (new_size > v_size){
		
		for (int i = v_size; i < new_size; ++i){
			
			v_ptr[i] = 0;
			++v_size;
		}
	}
}

template <typename T>
size_t MyVector<T>::capacity ()
{
	return v_capacity;
}

template <typename T>
bool MyVector<T>::empty ()
{
	return v_size > 0 ? false : true;
}

template <typename T>
void MyVector<T>::reserv (int n)
{
	if (n > v_capacity){
		
		MyVector<T>::reallocator(n);
	}
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
	if (v_size != v_capacity){
		
		MyVector<T>::reallocator(v_size);
	}
}


