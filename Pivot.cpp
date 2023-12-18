#include<iostream>
using namespace std;

int Pivot(int arr[],int size){
	int low=0;
	int high=size-1;
	
	int mid = low+(high-low)/2;
	
	while (low < high) {
        // Check if mid is the pivot
        if (arr[mid] > arr[0]) {
            low = mid + 1;
        } else {
            high = mid;
        }
        mid = low + (high - low) / 2;
    }
	
	return low;
}

int main(){
//	[2,2,2,3,2,2,2
	int a[10]={2,2,2,3,2,2,2};
	
	int ans = Pivot(a,7);
	cout<<ans;	
	return 0;
}