// subset1.cpp
#include<iostream>
using namespace std ;

void subset(int index,int sum ,vector<int> arr,vector<int> ds,int n){
	// base case
	if (index >= n)
	{
		cout << sum <<endl;
		ds.push_back(sum);
		return ;
	}
	// recursive case 
	// pick elment 
	subset(index+1,sum+arr[index],arr,ds,n);
	// not pick 
	subset(index+1,sum,arr,ds,n);
}

int main(){

	vector<int> arr{3,1,2};
	int size = arr.size();
	vector<int> ds;
	vector<vector<int> > ans ;
	subset(0,0,arr,ds,size);

}