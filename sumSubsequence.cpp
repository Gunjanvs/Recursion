#include<iostream>
#include<vector>
using namespace std ;

void SumSeq(int index ,vector<int>&ds,int arr[],int sum ,int s,int n){

    // base case 
    if (index >= n)
    {
        if (s == sum)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout <<ds[i] <<" ";
            }
            cout << endl;
            
        }
        return ;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    SumSeq(index+1,ds,arr,sum,s,n);
    ds.pop_back();
    s -= arr[index];
    SumSeq(index+1,ds,arr,sum,s,n);

    
}

bool SumSeq2(int index ,vector<int>&ds,int arr[],int sum ,int s,int n){

    // base case 
    if (index >= n)
    {
        // condition satisfied
        if (s == sum)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout <<ds[i] <<" ";
            }
            cout << endl;
            return true;
        }
        // codition not satisfied 
        else {
            return false ;
        }
        
    }
    ds.push_back(arr[index]);
    s += arr[index];
    // condition satisfied 
    if (SumSeq2(index+1,ds,arr,sum,s,n) == true )
    {
        return true ;
    }
    ds.pop_back();
    s -= arr[index];
    if (SumSeq2(index+1,ds,arr,sum,s,n) == true )
    {
        return true ;
    }
    return false;
}

int main(){
    int arr[]={1,2,1};
    int n = sizeof(arr)/sizeof(int);
    vector<int>ds;
    int sum = 3;
    SumSeq2(0,ds,arr,2,0,n);
    return 0;
}