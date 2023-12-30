// PrintAllpermu.cpp
#include<iostream>
#include<vector>
using namespace std ;

void Permutations(vector<int> &nums,int freq[] , vector<int> &ds , vector<vector<int> >&ans){
	// base case 
	if (ds.size() == nums.size())
	{
		ans.push_back(ds);
		return ;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (!freq[i])
		{
			ds.push_back(nums[i]);
			freq[i] =1;
			Permutations(nums,freq,ds,ans);
			freq[i] =0 ;
			ds.pop_back();
		}
	}
}

int main(){
	vector<int> nums {1,2,3};
	int n = nums.size();
	int freq[n] ;
	for (int i = 0; i < n; ++i)
	{
		freq[i] = 0;
	}
	vector<int> ds ;
	vector<vector<int> > ans ;
	Permutations(nums,freq,ds,ans);
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] <<" ";
		}
		cout << endl;
	}

}