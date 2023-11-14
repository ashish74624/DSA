#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the no stars";
	cin>>n;
//	for(int row=1;row<=n;row++){
//		for(int col=1;col<=n;col++){
//			cout<<"*";
//		}
//		cout<<endl;
//	}

//OR
	int row=1;
	while(row<=n){	
	int col=1;
		while(col<=n){
			cout<<"*";
			col++;
		}
		cout<<endl;
		row++;
	}

}
