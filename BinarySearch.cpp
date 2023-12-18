#include<iostream>
using namespace std;

int binarySearch(int a[],int size,int key){
	int low=0;
	int high = size-1;
	
	int mid = low + (high-low)/2;
	while(low<=high){
		if(a[mid]==key){
			return mid;
		}
		if(key>a[mid]){
			low=mid+1;
//			high=size-1;
		}else{
			high=mid-1;
		}
		mid = low + (high-low)/2;
	}
		return -1;
}

int main(){
	
	int even[10]={0,1,2,3,2,1,0};
//	int even[6]={2,5,6,9,10,14};
//	int odd[5]={3,9,5,6,4};
	
	int a= binarySearch(even,7,2);
//	int b = binarySearch(odd,5,6);
	
	
	cout<<"The key in even arr is found at :"<<a<<endl;
	
//	cout<<"The key in odd arr is found at :"<<b<<endl;
	return 0;
}