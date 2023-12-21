#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key,int i){
	if(i== n){
		return -1;
	}
	if(key == arr[i]){
		return i;
	}else{
		return linearSearch(arr,n,key,i+1);
	}
}

int main(){
	int arr[] ={1,2,3,4,5};
	int n = sizeof(arr)/ sizeof(arr[0]);
	int key =4;
	int i=0;
	int ans=-1;
	ans = linearSearch(arr,n,key,i);
	cout<<ans;
}