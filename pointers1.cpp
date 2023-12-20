#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	int num =5;
	
	cout<<"Address of num is : "<<&num<<endl;
	
	int *ptr = &num;
	
	cout<<"Value of num is : "<<*ptr<<endl;
	
	cout<<"Address of num is : "<<ptr<<endl;
	
	cout<<"Size of integer is : "<<sizeof(num)<<endl;
	cout<<"Size of inter is : "<<sizeof(ptr)<<endl;
	
	cout<<"Before : "<<num<<endl;
	(*ptr)++;
	cout<<"After : "<<num<<endl;
	
	//	Coping a pointer
	int *q = ptr;
	cout<<ptr<<"-"<<q<<endl;
	cout<<*ptr<<"-"<<*q<<endl;
	
	
} 