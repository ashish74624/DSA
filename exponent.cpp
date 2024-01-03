#include<iostream>
#include<math.h>
using namespace std;

int pow(int a , int b){
	
	if(b==0){
		return 1;
	}
	
	if(b==1){
		return a;
	}
	
	if(b%2==0){//b is even
		b=b/2;
		return pow(a,b)*pow(a,b/2);
	}else{
		return a*pow(a,b/2)*pow(a,b/2);
	}
	
}

int main(){

	int a= 2;
	int b=88;
	
	int ans=pow(a,b);
	
	cout<<ans<<endl;
	
} 