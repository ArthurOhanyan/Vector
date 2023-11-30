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
	
	~MyVector<bool>();
	
	  std::ostream& operator << (std::ostream& os)
	{
		for (int i = 0; i < v_capacity; ++i){
			
			os << v_ptr[i] << " ";
		}

		return os;
	
	}


};


MyVector<bool>::MyVector()
{
	v_ptr = nullptr;
	v_size = 0;
	v_capacity = 0;
}

MyVector<bool>::~MyVector()
{
	if (v_ptr){
		
		delete [] v_ptr;
	}
	v_size = 0;
	v_capacity = 0;
}



template <typename T>
std::ostream& operator << (std::ostream& os, MyVector<T>& vec){

	return vec.operator<<(os);

}

template <typename T>
MyVector<T>::MyVector() 
{
	v_ptr = nullptr;
	v_size = 0;
	v_capacity = 0;
}

template <typename T>
MyVector<T>::MyVector(int x, int y)
{
	v_capacity = x;
	v_size = 0;
	v_ptr = new T [v_capacity];
	for (int i = 0; i < x; ++i){
		
		v_ptr[v_size++] = y;
	}
	
}

template <typename T>
MyVector<T>::MyVector(std::initializer_list<int> list)
{
	
	
}

template <typename T>
MyVector<T>::~MyVector ()
{
	if (v_ptr != nullptr){
		std::cout << " destructor works " << std::endl;
		delete [] v_ptr;
	}
	v_size = 0;
	v_capacity = 0;
}

int main ()
{
	

	MyVector<bool> my_vec_bool;
	
	 for (int i = 0; i < 69; ++i){
		
		 if (i & 1){
		 
			my_vec_bool.push_back(true);
		} else {
			
			my_vec_bool.push_back(false);
		}
		 
	}
	 
	 my_vec_bool.print();
	
	std::cout << std::endl;

}


///////////////////////////////////////////////////
///////	       	VECTOR BOOL 		 //////////

void MyVector<bool>::push_back(const bool bl)
{
	//if (!v_ptr){
		
		//std::cout << " called MyVector<bool> push_back() function :: nullptr :: error " << std::endl;
		//exit(0);
      //	}
      	int elem = 0;
	size_t one = 1;
	int index = 0;

	if (v_capacity == 0 || v_size == faiq_cap){
		
		MyVector<bool>::reallocator();
		std::cout << " push_back :: reallocator :: v_capacity :: " << v_capacity << std::endl;
		std::cout << " push_back :: reallocator :: faiq_cap :: " << faiq_cap << std::endl;
	}
	
	if (bl) {
	
		elem = v_size / BITCOUNT;
		//std::cout << " elem = " << elem << std::endl;

		if (elem){
		
			index = v_size - (elem * BITCOUNT);
			std::cout << " push_back () :: if  elem " << std::endl;	

		} else {
			
			index = v_size;
			//std::cout << " index = " << index ;
		}

			v_ptr[elem] ^= (one << index);
			//std::cout << (bool)(v_ptr[elem] ^ (1 << index)) << std::endl;
			++v_size;
	} else {
	
		++v_size;
	}	

}

std::ostream& operator << (std::ostream& os, MyVector<bool>& vec){

	return vec.operator<<(os);

}

void MyVector<bool>::print ()
{
	std::cout << " print () :: size = " << v_size << ", cap = " << v_capacity << std::endl;
	int tmp_size = v_size;
	int tmp = 0;
	size_t one = 1;
	for (int i = 0; i < v_capacity; ++i){
		
		if (tmp_size / BITCOUNT){
			
			tmp = BITCOUNT;
			//std::cout << " if {}  tmp :: = " << tmp << std::endl;

		} else {
		
			tmp  = tmp_size;
			//std::cout << " else {} tmp :: = " << tmp << std::endl;
		}

		for (int j = 0; j < tmp; ++j){
		
			std::cout << " " << (bool)(v_ptr[i] & (one << j));

		}
			
		tmp_size -= BITCOUNT;

	}
	
}

int MyVector<bool>::size ()
{
	return v_size;
}

void MyVector<bool>::resize (int new_size)
{
	if (new_size > faiq_cap){
			
		MyVector<bool>::reallocator(new_size);

	} else if (new_size < v_size){
	
		
	}


}
///////////////////////////////////////////////////
///////					 //////////
///////	       	VECTOR BOOL 		 //////////
//////////////////////////////////////////////////

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
void MyVector<T>::resize (const int new_size)
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
void MyVector<T>::reserv (const int n)
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


template <typename T>
T& MyVector<T>::at (const int n)
{
	if (!v_ptr){
		
		std::cout << " at() function :: nullptr :: error " << std::endl;
		//exit(0);
	}

	if (n >= v_size || n < 0){
		
		std::cout << " at() function :: out_of_range " << std::endl;
		exit(0);
	} else {
	
		return v_ptr[n];
	}
}

template <typename T>
T& MyVector<T>::front ()
{
	if (!v_ptr){
		
		std::cout << " front () function :: nullptr :: error " << std::endl;
		exit(0);
	}

	return v_ptr[0];
}

template <typename T>
T& MyVector<T>::back ()
{
	if (!v_ptr){
		
		std::cout << " back () function :: nullptr :: error " << std::endl;
		exit (0);
	}

	return v_ptr[v_size - 1];
}

template <typename T>
T* MyVector<T>::data ()
{
	return v_ptr;
}

template <typename T>
void MyVector<T>::assign (int count,const T& value)
{

	if (count > v_capacity){
		
		v_capacity = count + 5;
	}

	T* tmp = new T [v_capacity];
	for (int i = 0; i < count; ++i){
		
		tmp [i] = value;
	}
	v_size = count;
	if (!v_ptr){
		
		delete [] v_ptr;
	}
	v_ptr = tmp;
	tmp = nullptr;
}

template <typename T>
void MyVector<T>::push_back (const T& val)
{
	if (!v_ptr){
		
		std::cout << " called push_back() :: nullptr :: error " << std::endl;
		exit(0);	
	}

	if (v_capacity == 0 || v_size == v_capacity){
		
		MyVector<T>::reallocator();
	}	

	v_ptr[v_size++] = val;
}

template <typename T>
void MyVector<T>::pop_back () 
{
	if (!v_ptr){
		
		std::cout << " called pop_back() :: nullptr :: error " << std::endl;
		exit(0);
	}

	if (v_size > 0){
		
		--v_size;
	}
}

template <typename T>
int MyVector<T>::insert (const int pos,const T& val)
{
	int index = 0;
	if (!v_ptr){
		
		std::cout << " called insert () :: nullptr " << std::endl;
		exit(0);
	}

	if (pos < 0 || pos > v_size){
		
		std::cout << " invalid position :: segmentation fault " << std::endl;
	       	exit (0);

	} else {

		if (v_size == v_capacity){
			
			MyVector<T>::reallocator();
		}

		for (int i = v_size; i >= pos - 1; --i){
			
			if (i == pos - 1){
				
				v_ptr[i] = val;
				++v_size;
				index = i;
				break;
			}

			v_ptr[i] == v_ptr[i-1];
		}
	}
	return index;
}

template <typename T>
int MyVector<T>::erase (const int pos)
{

	if (!v_ptr){
		
		std::cout << " called erase () :: nullptr :: error " << std::endl;
		exit(0);
	}

	if (pos < 0 || pos > v_size){
		
		std::cout << " erase () fuctoin :: invalid argument " << std::endl;
		exit(0);
	} else {
		
		for (int i = pos - 1; i < v_size - 1; ++i){
			
			v_ptr[i] = v_ptr[i+1];
		}
		--v_size;
	}

	return pos - 1;
} 

template <typename T>
void MyVector<T>::swap (MyVector& obj)
{
	T* tmp = v_ptr;
	int tmp_size = obj.size();
	int tmp_capacity = obj.capacity();
	v_ptr = obj.setter();
	obj.setter (tmp,v_size,v_capacity);
	v_size = tmp_size;
	v_capacity = tmp_capacity;
	tmp = nullptr;

}

template <typename T>
void MyVector<T>::clear ()
{
	if (!v_ptr){
		
		std::cout << " called clear :: nullptr :: error " << std::endl;
		exit (0);
	}

	if (v_size != 0){
		
		v_size = 0;
	}
	
}






