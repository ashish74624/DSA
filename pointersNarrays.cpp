#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	
	/*int a[10]={1,2,3,4,5,6,7,8,9};
	
	cout<<"Address of firt memory block is : "<<a<<endl;
	cout<<"Address of firt memory block is : "<<&a[0]<<endl;
	cout<<"Address of firt memory block is : "<<&a<<endl;
	cout<<*a<<endl;// value at memory 'a';
	cout<<*(a+1)<<endl;//value at memory 'a+1';
	cout<<(*a)+2<<endl;//value at memory 'a'+2==3;
	
	cout<<"2nd index Element is "<<a[2]<<endl;
	cout<<"2nd index Element is "<<*(a+2)<<endl;
	
	int i=2;
	cout<<"i[a] : "<<i[a]<<"=="<<" *(i+a) : "<<*(i+a)<<endl;
	*/
	int temp [10] = {1,2};
	cout << sizeof(temp) << endl;
	cout << sizeof(*temp) << endl;
	int *ptr = &temp [0];
	cout<< sizeof(ptr) << endl ;
	cout<< sizeof(*ptr) << endl;
	cout << sizeof(&ptr) << endl;
} 