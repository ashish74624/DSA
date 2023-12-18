#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	int a[20];
	int size;
	cout<<"Enter size"<<endl;
	cin>>size;
	if(size==0){
		cout<<"Exit";
		exit(0);
	}
	cout<<"Enter Array elem"<<endl;
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	
	int j=1;
	for(int i=0;i<size;i++){
		if(i>size || j>size ){
			break;
		}else{
		
		
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		cout<<"i:"<<i<<endl;
		cout<<"j:"<<j<<endl;
		i=i+1;
		j=j+2;
	}
	}
	for(int i=0;i<size;i++){
		cout<<a[i];
	}
	
} 