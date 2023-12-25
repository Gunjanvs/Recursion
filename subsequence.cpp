#include<iostream>
using namespace std ;

void subsequence(int index , vector<int>&ds ,int arr[],int n){
    if (index == n)
    {
        // print the output 
        for(int i = 0 ; i < ds.size() ; i++){
            cout << ds[i]<<" ";
        }
        cout << endl;
        return ;
    }
    // take the element
    ds.push_back(arr[index]);
    subsequence(index +1,ds,arr,n);
    // dont take 
    ds.pop_back();
    subsequence(index+1,ds,arr,n);

    
}
int countSubsequences(int index, vector<int>& ds, int arr[], int n) {
    if (index == n) {
        // Uncomment the following lines if you want to print the subsequences
        /*
        for (int i = 0; i < ds.size(); i++) {
            cout << ds[i] << " ";
        }
        cout << endl;
        */
        return 1; // Return 1 for each subsequence
    }

    // Take the element
    ds.push_back(arr[index]);
    int countWithElement = countSubsequences(index + 1, ds, arr, n);
    // Don't take the element
    ds.pop_back();
    int countWithoutElement = countSubsequences(index + 1, ds, arr, n);

    return countWithElement + countWithoutElement;
}

int main(){
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(int);
    int count = 0 ;
    vector<int> ds;
    subsequence(0,ds,arr,n);
    // subsequenceCount(0,ds,arr,n,count);
    cout << count;
    return 0 ;
}