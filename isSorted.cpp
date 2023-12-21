#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

bool isSorted(int arr[],int n,int i){
	
	if(i==n-1){
		return true;
	}
	
	if(n==0 || n==1){
		return true;
	}
	if(arr[i]>arr[i+1]){
	 return false;}
	else{
	 bool ans = isSorted(arr,n,i+1);
}
			
}

int main(){
	
	int arr[] = {1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i=0;
	if(isSorted(arr,n,i)){
		cout<<"Array is Sorted"<<endl;
	}else{
		cout<<"Array is not Sorted"<<endl;
	}
	
} 