// combinatonsum2.cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;

void combinationSum(int index ,int target ,vector<int>&ds,int n,vector<int>arr,vector<vector<int> >&ans){
	// base case 
	if (target == 0)
	{
		ans.push_back(ds);
		return;
	}

	// move to every index 
	for (int i = index; i < arr.size(); ++i)
	{
		// check condition 
		if (i > index && arr[i] == arr[i-1])continue;
		if (arr[i] >target)break;
		ds.push_back(arr[i]);
		combinationSum(i+1,target-arr[i],ds,n,arr,ans);
		ds.pop_back();
	}
}

int main(){

	vector<int> arr{10,1,2,7,6,1,5};
	vector<int>ds;
	vector<vector<int>> ans;
	int size = arr.size();
	sort(arr.begin(),arr.end());
	combinationSum(0,8,ds,size,arr,ans);
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j]<<" ";
		}
		cout << endl;
	}
}