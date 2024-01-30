// arthimeticSlicesII.cpp
#include<iostream>
using namespace std ;

bool isArthimetic(vector<int>&ds){
	int diff = ds[1]-ds[0] ;
	for (int i = 0; i < ds.size()-1; ++i)
	{
		if (ds[i+1] -ds[i] != diff)
		{
			return false;
		}
	}
	return true ;
}

int numberOfArithmeticSlices(int index ,vector<int>& nums,vector<int>&ds,vector<vector<int> >&ans) {
        // base. case 
	if (index >= nums.size())
	{
		if (ds.size()>=3)
		{
			if (isArthimetic(ds))
			{
				ans.push_back(ds);
				return 1;
			}
		}
		return 0;
	}

	// take element 
	ds.push_back(nums[index]);
	int count1 = numberOfArithmeticSlices(index+1,nums,ds,ans);
	// remove 
	ds.pop_back();
	int count2 = numberOfArithmeticSlices(index+1,nums,ds,ans);

    return count1+count2;
}

int main(){

	vector<int> nums{7,7,7,7,7};
	vector<int> ds;
	vector<vector<int> > ans ;
	cout << numberOfArithmeticSlices(0,nums,ds,ans)<< endl;

	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] <<" ";
		}
		cout << endl;
	}
        
    
}