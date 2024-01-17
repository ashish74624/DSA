#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=i+1;
        bool same=false;
        int cnt=0;
        int curr=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                if(curr>1){
                    cnt++;
                    curr++;
                }else{
                    curr++;
                }
            }else{
                curr=1;
            }
        }
        cout<<cnt<<endl;
        while(i<nums.size()-cnt){
            print(nums);
            if(nums[i]==nums[j]){
                if(same){
//                	cout<<i<<endl;
                    while(j<nums.size()-1){
                        nums[j]=nums[j+1];
                        j++;
                    }
                    j=i+1;
                    if(nums[i]!=nums[j]){
                        same=false;
                        i++;
                        j++;
                    }
                }
                else{
                    same=true;
                    i++;
                    j++;
                }
            }
            else{
                same=false;
                i++;
                j++;
            }
            
        }
        // cout<<cnt<<endl;
        return nums.size();
    }
    
    int main(){
    	vector<int> a= {1,1,1,2,2,3};
    	removeDuplicates(a);
	}