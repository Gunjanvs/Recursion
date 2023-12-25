#include<iostream>
using namespace std ;

int subsequence(int index,vector<char>&ds,string s,int n){
    if (index >= n)
    {
        return 1;
    }

    // take elements from the index 
    ds.push_back(s[index]);
    int countWE = subsequence(index+1,ds,s,n);
    // not take elements from the index 
    ds.pop_back();
    int countWOE = subsequence(index+1,ds,s,n);
    return countWE+countWOE;

    
}

int main(){

    string s = "gfg";
    int n = s.size();
    vector<char>ds;
    cout << subsequence(0,ds,s,n);
    return 0 ;

}