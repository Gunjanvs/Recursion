#include<iostream>
using namespace std ;

int SumSeq(int index ,int arr[],int sum ,int s,int n){

    // base case 
    if (index >= n)
    {
        if (s == sum)return 1;
        else return 0;
    }
    s += arr[index];
    int l =SumSeq(index+1,arr,sum,s,n);
    s -= arr[index];
    int r = SumSeq(index+1,arr,sum,s,n);
    return l+r;   
}

int main(){
    int arr[]={1,2,1};
    int n = sizeof(arr)/sizeof(int);
   
    int sum = 4;
    cout << SumSeq(0,arr,sum,0,n);
    return 0;
}