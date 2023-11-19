#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n";
	cin>>n;
	int row=1;
	while(row<=n){
//		Space triangle
		int col=1;
		while(col<=(n-(row-1))){
			cout<<col;
			col++;
		}
//		2nd triangle
		int star=(2*row)-2;
		while(star)//jab tk star zero nhi ho jata tb tk print it.
		{
			cout<<"*";
			star--;
		}
//		3rd triangle
		int col2= n-(row-1);
		while(col2){
			cout<<col2;
			col2--;
		}
		
		cout<<endl;
		row++;
		
	}
	return 0;
}