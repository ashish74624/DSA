#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n";
	cin>>n;
	int row=1;
	while(row<=n){
		int space= row-1;
		while(space<row){
			cout<<" ";
			space++;
		}
		int col=1;
		while(col<=n){
			cout<<"*";
			col++;
		}
		cout<<endl;
		row++;
		
	}
	return 0;
}