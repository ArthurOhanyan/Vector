#include <iostream>
#include <climits>
template <typename T>
class MyVector
{
	T* v_ptr;
	int v_size;
	int v_capacity;

	void reallocator (int x = 0){
			
		if (v_capacity == 0){
			
			v_capacity = 10;

		} else if (x == 0){
			
			v_capacity *= 2;
		} else {
			
			v_capacity = x + 5;
		}
		T* tmp = new T [v_capacity];
		for (int i = 0; i < v_size; ++i){
			
			tmp [i] = v_ptr[i];
		}	
		delete [] v_ptr;
		v_ptr = tmp;
		tmp = nullptr;
	}

	public:
	MyVector ();
	MyVector (int,int);
	MyVector (std::initializer_list<int>);
	MyVector (const MyVector&);
	MyVector (MyVector&&);
	
       	~MyVector ();

	int size ();
	size_t max_size ();
	void resize (const int);
	size_t capacity ();
	bool empty ();
	void reserv (const int);
	void shrink_to_fit();
	T& at (int);
	T& front ();
	T& back ();
	T* data ();
	void assign (int,const T&);
	void push_back (const T&);
	void pop_back ();
	int insert (const int,const T&);
	int erase (const int);
	void swap (MyVector&);
	void clear ();
	
	T* setter (T* ptr = nullptr, int size = 0, int capacity = 0)
	{
		if (ptr){
		
			v_ptr = ptr;
			v_size = size;
			v_capacity = capacity;
		} else {
		
			return v_ptr;
		}

		return nullptr;
	}

	  std::ostream& operator << (std::ostream& os)
	{
		for (int i = 0; i < v_size; ++i){
			
			os << v_ptr[i] << " ";
		}

		return os;
	
	}

	  MyVector& operator = (const MyVector& obj)
	  {
		
		v_size = obj.v_size;
		v_capacity = obj.v_capacity; 
	  	delete [] v_ptr;
		v_ptr = new T [v_capacity];
		for (int i = 0; i < v_size; ++i){
			
			v_ptr[i] = obj.v_ptr[i];
		}
	  	return *this;
	  }

	  MyVector& operator = (MyVector&& obj)
	  {
	  	
		v_size = obj.v_size;
		v_capacity = obj.v_capacity;
		delete [] v_ptr;
		v_ptr = new T [v_capacity];
		for (int i = 0; i < v_size; ++i){
			
			v_ptr[i] = obj.v_ptr[i];
		}
		delete [] obj.v_ptr;
		obj.v_ptr = nullptr;
		obj.v_size = 0;
		obj.v_capacity = 0;
		return *this;
	  }

	  T& operator [] (size_t index)
	  {
	  	if (!v_ptr){
			
			std::cout << " operator [] called :: nullptr :: error " << std::endl;
			exit(0);

		} else if (index < 0 || index >= v_size){
		
			std::cout << " The index out of range :: segment error " << std::endl;
			exit (0);
		}
			
		return v_ptr[index];
	  	
	  }

	 
};

template <>
class MyVector<bool>
{
	size_t* v_ptr;
	int v_size;
	int v_capacity;
	int BITCOUNT = sizeof(size_t) * 8;
	int faiq_cap;	

	void reallocator (int new_size = 0){
	
		if (new_size){
		
			int tmp_cap = v_capacity;
			v_capacity = (new_size / BITCOUNT) + 1;
			faiq_cap = new_size;

			size_t* tmp = new size_t [v_capacity];
			for (int i = 0; i < tmp_cap; ++i){
			
				tmp [i] = v_ptr[i];
			}
			delete [] v_ptr;
			v_ptr = tmp;
			tmp = nullptr;

		
		} else {

			int tmp_cap = v_capacity;
			++v_capacity;
			faiq_cap = v_capacity * BITCOUNT;
		
			size_t* tmp = new size_t [v_capacity];
			for (int i = 0; i < tmp_cap; ++i){
			
				tmp [i] = v_ptr[i];
			}	
			delete [] v_ptr;
			v_ptr = tmp;
			tmp = nullptr;
		
		}
	}
	
	public:
	void push_back(const bool);
	void resize(int);
	void print ();
	int size ();

	MyVector<bool>();
	MyVector<bool>(const MyVector<bool>&);
	MyVector<bool>(MyVector<bool>&&);
	~MyVector<bool>();
	
	  std::ostream& operator << (std::ostream& os)
	{
		for (int i = 0; i < v_capacity; ++i){
			
			os << v_ptr[i] << " ";
		}

		return os;
	
	}

	 ///////// class reference //////////

	  class reference 
	  {
		private: 
			size_t* ptr;
			size_t index;
			bool flag;

	  	public:
			reference (size_t* ptr,size_t index);
			reference (const reference& obj);
			reference& operator=(const reference& obj);
			reference& operator=(bool flag);
		   	operator bool ();
			void flip();
	
	  };
	  MyVector<bool>::reference operator [] (size_t index);

};

#include "implementation.hpp"





