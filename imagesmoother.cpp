#include<iostream>
using namespace std ;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));


        for(int x = 0 ; x < rows ; x++){
            for(int y = 0 ; y < cols ; y++){
                int total = 0,count =0;
                // now start the iterating the elements 
                for(int i = rows-1; i < rows+2;i++){
                    for(int j =cols-1;j<cols+2;j++){
                        if(i < 0 || i == rows || j <0 || j == cols)continue;
                        total += img[i][j];
                        count += 1;
                    }
                    
                }
                int average = total/count;
                res[x][y]=average ;

            }
        }
        return res;
    }
};

int main(){

}