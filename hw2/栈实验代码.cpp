#include"stack.h"
#include<iostream>
using namespace std;
int main()
{
	Stack<int> b;
	b.push(32);
	b.push(56);
	cout<<b.top()<<endl;
	b.pop();
	cout<<b.top();
	b.pop();
	if (b.empty()){
	
	cout<< "is empty"<<endl;}

	else{
	 cout<<"isnt empty"<<endl;}
	return 0;
 } 
