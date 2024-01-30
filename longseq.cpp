// longestCommonSub.cpp
#include<iostream>
#include<algorithm>
using namespace std;

void common(string s,int index,vector<string> &ds,string res){
	if (index >= s.length())
	{
		ds.push_back(res);
		return;
	}

	common(s,index+1,ds,res);

	res += s[index];
	common(s,index+1,ds,res);

}

int longestCommonSubsequence(string text1, string text2) {
	vector<string>ds;
	int ans =0 ;
	// vector<string>ds2;
	string res="";
	common(text1,0,ds,res);
	res="";
	common(text2,0,ds,res);
	sort(ds.begin(),ds.end());
	for(int i =1 ;i < ds.size();i++){
		if (ds[i] == ds[i-1])
		{
			int len = ds[i].length();
			ans = max(ans,len);
		}
	}

	return ans;
}

int main(){
	string text1="bsbininm";
	string text2="jmjkbkjkv";
	cout << longestCommonSubsequence(text1,text2);
}