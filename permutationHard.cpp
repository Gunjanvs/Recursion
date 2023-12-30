// permutationHard.cpp
#include<iostream>
using namespace std ;

void permutations(int i ,vector<int> &a,vector<vector<int> > &ans){
	if (a[i] == '\0')
	{
		ans.push_back(a);
	}

	for (int j = i; a[j] != '\0'; ++j)
	{
		swap(a[i], a[j]);
		permutations(i + 1,a,ans);

		// Backtracking
		swap(a[i], a[j]);
	}
}

int main(){

	vector<int> arr{1,2,3};
	vector<vector<int> > ans;
	permutations(0,arr,ans);
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] <<" ";
		}
		cout << endl;
	}
}