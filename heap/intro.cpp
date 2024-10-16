#include<iostream>
#include<queue>
using namespace std;

class heap{
	public:
		int arr[100];
		int size;
		
		heap(){
			arr[0]=-1;
			size=0;
		}
		
		void insert(int val){ // O(logn)
			size=size+1;
			int index=size;
			arr[index]=val;
			
			while(index>1){
				int parent= index/2;
				
				if(arr[parent]<arr[index]){
					swap(arr[parent],arr[index]);
					index=parent;
				}else{
					return;
				}
			}
			
		}
		
		void print() {
			for(int i = 1; i<=size; i++) {
				cout << arr[i] << " ";
			}cout << endl;
		}
		
		void deleteFromHeap(){ // O(logn)
			if(size=0){
				cout<<"Nothing to delete"<<endl;
				return;
			}
			// step 1 : replace fisrt elem with last
			arr[1]=arr[size];
			size--;
			
			int i=1;
			
			while(i<size){
				int leftIndex= 2*i;
				int rightIndex= 2*i+1;
				
				if(leftIndex<size && arr[i]<arr[leftIndex] ){
					swap(arr[i],arr[leftIndex]);
					i=leftIndex;
				}
				else if(rightIndex<size && arr[i]<arr[rightIndex] ){
					swap(arr[i],arr[rightIndex]);
					i=rightIndex;
				}
				else{
					return;	
				}
			}
			
		}
};

void heapify(int arr[],int n,int i){
	int largest =i;
	int leftSide = 2*i;
	int rightSide = 2*i+1;
	
	if(leftSide<=n && arr[largest] < arr[leftSide] ){
			largest=leftSide;
	}
	
	if(rightSide<=n && arr[largest] < arr[rightSide] ){
		largest=rightSide;
	}
	
	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
	
}

void heapSort(int arr[],int n){
	int t=n;
	
	while(t>1){
		// Step 1 : swap
		swap(arr[1],arr[t]);
		t--;
		
		// Step 2 : heapify
		heapify(arr,t,1);
	}
}

int main(){
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	
	h.insert(54);
	h.print();
	
	// Heap creation
	int arr[6] ={-1,54,53,55,52,50};
	int n=5;
	for(int i=n/2 ;i>0;i--){
		heapify(arr,n,i);
	}
	
	cout<<"Printed array after heapify"<<endl;
	for(int i = 1; i<=n; i++) {
		cout << arr[i] << " ";
	} cout << endl;
	
	heapSort(arr,n);
	
	cout<<"Printed array after heap sort"<<endl;
	for(int i = 1; i<=n; i++) {
		cout << arr[i] << " ";
	} cout << endl;
	
	cout << "using Priority Queue here" << endl;
	//maxheap
	priority_queue<int> pq;
	pq.push(4);
	pq.push(2);
	pq.push(5);
	pq.push(3);
	cout << "element at Top " << pq.top() << endl;
	pq.pop();
	cout << "element at Top " << pq.top() << endl;
	cout << " Size is " << pq.size() << endl;
	if (pq.empty()){
		cout<<"Pq is empty"<<endl;
	}else{
		cout<<"Pq is not empty"<<endl;
	}
	
	//min heap
	priority_queue<int, vector<int>, greater<int> > minheap;
	minheap.push(4);
	minheap.push(2);
	minheap.push(5);
	minheap.push(3);
	cout << "element at Top" << minheap.top() << endl;
	
	minheap.pop();
	cout << "element at Top " << minheap.top() << endl;
	cout << " Size is " << minheap.size() << endl;
	if (minheap.empty()) {
	cout << "minheap is empty" << endl;
	}
	else {
	cout << "minheap is not empty"<< endl;
	}
	
	return 0;
}