#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		
		void addEdge(int u, int v,bool direction){
			// direction = 0 -> undirected 
			// direction = 1 -> directed 
			
			adj[u].push_back(v);
			if(direction==0){
				adj[v].push_back(u);	
			}
		}
		
		void printAdj(){
			for(auto i:adj){
				cout<<i.first<<"->";
				for(auto j: i.second){
					cout<<j<<",";
				}
				cout<<endl;
			}
		}
};

int main(){
	
	graph g;
	
	cout<<"Enter number of nodes"<<endl;
	int n;
	cin>>n;
	
	cout<<"Enter the number of edges"<<endl;
	int m;
	cin>>m;
	
	for(int i=0;i<m;i++){
		int u,v;
		cout<<"Enter u,v values"<<endl;
		cin>> u;
		cin>>v;
		g.addEdge(u,v,0);
	}
	
	g.printAdj();
	
	return 0;
}