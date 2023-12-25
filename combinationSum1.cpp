// combinationSum1.cpp
#include<iostream>
#include<vector>
using namespace std ;

void combinationSum(int index ,int target ,vector<int>&ds,int n,vector<int>arr){
	// base case 
	if (index == n)
	{
		if (target == 0)
		{
			for (int i = 0; i < ds.size(); ++i)
			{
				cout << ds[i]<<" ";
			}
			cout << endl;
			return ;
		}
		else return ;
	}

	// recursive case 
	// pick the element
	if (arr[index] <= target)
	{
		ds.push_back(arr[index]);
		combinationSum(index,target-arr[index],ds,n,arr);
		ds.pop_back();
	}
	// not pick element 
	
	combinationSum(index+1,target,ds,n,arr);
}

int main(){

	vector<int> arr{2,3,6,7};
	vector<int>ds;
	int size = arr.size();
	combinationSum(0,7,ds,size,arr);
}