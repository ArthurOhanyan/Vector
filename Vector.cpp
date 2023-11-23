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
	//MyVector (initialization_list<int>);
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
	v_capacity = 10;
	v_size = 0;
	v_ptr = new T [v_capacity];
	for (int i = 0; i < x; ++i){
		
		v_ptr[v_size++] = y;
	}
	
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
	
	MyVector<int> my_vec;
	MyVector<int> my_vec2;
	MyVector<int> my_vec3(3,17);
	std::cout << " my_vec3 size " << my_vec3.size() << " capacity = " << my_vec.capacity() << " :: " << my_vec3 << std::endl;
	std::cout << " the size is : " << my_vec.size() << std::endl;
	//std::cout << " the max size is : " << my_vec.max_size() << std::endl;
	std::cout << " the capacity is : " << my_vec.capacity() << std::endl;
	//my_vec.resize (5);
	//std::cout << " the size after resize is : " << my_vec.size() << std::endl;
	//std::cout << " The capacity is :: " << my_vec.capacity() << std::endl;
	//std::cout << std::boolalpha << " my_vec.empty () :: " << my_vec.empty() << std::endl;
        //my_vec.reserv (15);
	std::cout << std::endl;
       // std::cout << " after reserv capacity () :: " << my_vec.capacity () << std::endl;	
	//my_vec.shrink_to_fit();
	//std::cout << " after shrink to fit capacity is :: " << my_vec.capacity() << std::endl;
	//std::cout << " at () function called :: " << my_vec.at(2) << std::endl;
	//std::cout << " front () function called :: " << my_vec.front() << std::endl;
	//std::cout << " back () function called :: " << my_vec.back() << std::endl;
	my_vec.assign(3,8);
	my_vec2.assign(5,7);
	std::cout << " my_vec :: " << my_vec << std::endl;
	std::cout << " my_vec2 :: " << my_vec2 << std::endl;
	
	for (int i = 0; i < my_vec.size(); ++i){
		
		my_vec.at(i) = i;
		std::cout << " " << *(my_vec.data() + i);
	}
	std::cout << std::endl;
	for (int i = 0; i < my_vec2.size(); ++i){
		
		my_vec2.at(i) = i;
		std::cout << " " << *(my_vec2.data() + i);
	}
	my_vec.swap(my_vec2);
	std::cout << std::endl;
	std::cout << " after swap function " << std::endl;
	std::cout << my_vec << std::endl;
	std::cout << my_vec2 << std::endl;
	///my_vec.clear();
	//std::cout << "my_vec after clear :: " << my_vec << std::endl;
	std::cout << std::endl;
	my_vec2 = my_vec;
	std::cout << "my_vec after copy asigment my_vec = my_vec2  :: "  << my_vec << std::endl;
	std::cout << "my_vec2 after copy asigment my_vec = my_vec2 :: " << my_vec2 << std::endl;
	my_vec2 = std::move(my_vec);
	std::cout << " my_vec after move assigment " << my_vec << std::endl;
	std::cout << " my_vec2 after move assigment " << my_vec2 << std::endl;
	std::cout << " used operator [] " << my_vec2[2];
	
	//std::cout << " initilized with function at (), and print with function data () " << std::endl;
	//my_vec.assign (10,9);
	//std::cout << " after call my_vec.assign (10,9) :: "  << my_vec;
	//std::cout << "\n size is :: " << my_vec.size() << " :: capacity is :: " << my_vec.capacity() << std::endl;
	
	//int a = 17;
	//my_vec.push_back(a);
	//std::cout << " after push_back () call :: " << my_vec << std::endl;
	//std::cout << " size :: " << my_vec.size() << " \n capacity :: " << my_vec.capacity()  << std::endl;
	//my_vec.pop_back();
	//std::cout << " after pop_back () :: " << my_vec << std::endl;
	//std::cout << " size :: " << my_vec.size() << std::endl;
	//std::cout << std::endl;
	//int insert_index = my_vec.insert(3,a);
	//std::cout << " inserted element " << a << " in position " << insert_index << std::endl;
	//std::cout << " afetr insertion " << my_vec;
	//std::cout << " size :: " << my_vec.size() << std::endl;
	//int erase = my_vec.erase(6);
	//std::cout << " erased element in position " <<  erase << std::endl;
	//std::cout << my_vec << std::endl;
	std::cout << std::endl;

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






