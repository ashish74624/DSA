#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number";
	cin>>n;
	if(n==1){
		cout<<"1 , not a prime number";
	}
	int i=2;
	while(i<n){
		if(n%i==0){
			cout<<"Not Prime"<<endl;
			break;
		}
		else{
			cout<<"Prime"<<endl;
			break;
		}
		i++;
	}
	
}