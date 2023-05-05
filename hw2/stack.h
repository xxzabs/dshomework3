#include<iostream>
#include"../vector/vector1.h" 
template <typename T> class Stack{
 	
protected:
	
	int _size=0;
	T* elem;
 public:
	Stack(){elem=new T[100000];}
	void push(T const& e){_size++;elem[_size]=e;}
	void pop(){elem[_size]='\0';_size--;}
    T top(){return elem[_size];}
    bool empty() {return !_size;}
    int size(){return _size;}
    
  };
  
/*template <typename T,size_t N>
size_t size(const T(&)[N]){
	
return N;
}
template <typename T>
bool empty(Stack<T>st){
	return size_t()==0; 
}*/
