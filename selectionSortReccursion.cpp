#include<iostream>
#include<math.h>
using namespace std;

void selectionSort(int *arr,int n){
	
	if(n==0){
		return;
	}
	
	for(int i=1;i<n;i++){
		if(arr[0]>arr[i]){
			swap(arr[0],arr[i]);
		}
	}
	selectionSort(arr+1,n-1);
	
}                   


int main(){
	
	int arr[] = {6,8,3,5,4};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr,n);
	cout<<"ANS"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" "<<endl;
	}
	
	return 0;
	
} 