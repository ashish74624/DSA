#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n";
	cin>>n;
	int row=1;
	while(row<=n){
//		Space triangle
		int space=n-row;
		while(space){
			cout<<" ";
			space--;
		}
//		2nd triangle
		int col=1;
		while(col<=row){
			cout<<col;
			col++;
		}
//		3rd triangle
		int col2=row-1;
		while(col2){
			cout<<col2;
			col2--;
		}
		cout<<endl;
		row++;
		
	}
	return 0;
}