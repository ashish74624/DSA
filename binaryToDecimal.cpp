#include<iostream>
#include<math.h>
using namespace std;

int main(){
	cout<<"Enter binary Number"<<endl;
	int n;
	cin>>n;
	int ans=0;
	int i=0;
	while(n!=0){
		int digit = n % 10;//yha comp binary input ko digital ki tarah treat kr rha h so didgit nikalo
		if (digit==1){
			ans = ans+ pow(2,i);
		}
		n=n/10;
		i++;
	}
	cout<<"Ans = "<<ans<<endl;
} 