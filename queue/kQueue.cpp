#include<iostream>
#include<vector>
using namespace std;

class kQueue{
	public:
		int n;
		int k;
		int * arr;
		int* next;
		int * front;
		int * rear;
		int freeSpot;
	public:
		kQueue(int n,int k){
			this->n=n;
			this->k=k;
			front = new int [k];
			rear= new int[k];
			// initialize front and rear
			for(int i=0;i<k;i++){
				front[i]=-1;
				rear[i]=-1;
			}
			arr = new int[n];
			freeSpot = 0;
			next = new int [n];
			for(int i=0;i<n;i++){
				next[i]=i+1;
			}
			next[n-1]=-1;
		}
		
		void push(int x,int m){
			
			// overflow
			if(freeSpot==-1){
				cout << "No Empty space is present" << endl;
				return ;
			}
			
			int index= freeSpot;
			
			//update freeSpot
			freeSpot = next[index];
			
			if(front[m-1]==-1){
				front[m-1] = index;
			}
			else{
				// link new element to prev. element
				next[rear[m-1]]=index;
			}
			//update next for this element
			next[index]=-1;
			
			//update rear
			rear[m-1]=index;
			
			//push element
			arr[index]= x;
			
			cout<<arr[index]<<" pushed"<<endl;
			
		}
		
		int pop(int m){
			if(front[m-1]==-1){
				cout<<"Queue Empty"<<endl;
				return -1;
			}
			
			// index to pop
			int index = front[m-1];
			
			//update front 
			front[m-1] = next[index];
			
			//update next
			next[index]= freeSpot;
			
			//update freeSpot
			freeSpot=index;
			return arr[index];
			
		}
		
		
};

int main(){
	kQueue q(10, 3);
    q.push(10, 1);
    q.push(15,1);
    q.push(20, 2);
    q.push(25,1);

    cout << q.pop(1) << endl;
    cout << q.pop(2) << endl;
    cout << q.pop(1) << endl;
    cout << q.pop(1) << endl;

    cout << q.pop(1) << endl;

    return 0;
	
}