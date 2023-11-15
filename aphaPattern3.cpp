#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n";
	cin>>n;
	int row=1;
	while(row<=n){
		int col=1;
		while(col<=row){
			char ch = 'A' +n -(row-col+1);
			cout<<ch;
			col++;
		}
		cout<<endl;
		row++;
	}
	return 0;
}