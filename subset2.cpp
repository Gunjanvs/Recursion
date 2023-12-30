// subset2.cpp
#include<iostream>
using namespace std ;

void subset2(int index ,vector<int> &arr,vector<int> &ds ,vector<vector<int> > &ans){

	// base case 
	// if (index == n)
	// {
	// 	/* code */
	// }
	// recursive case 
	ans.push_back(ds);
	for (int i = index; i < arr.size(); ++i)
	{
		if (i != index && arr[i] == arr[i-1])continue;
		ds.push_back(arr[i]);
		subset2(i+1,arr,ds,ans);
		ds.pop_back();
	}
}

int main(){
	vector<int> arr{1,2,3,2,3,2};
	vector<int>ds;
	vector<vector<int> > ans ;
	sort(arr.begin(),arr.end());
	subset2(0,arr,ds,ans);

	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] <<" ";
		}
		cout << endl;
	}
}