// outofBoundarypath.cpp
#include <iostream>
using namespace std;
int checkBoundary(int m, int n, int maxMove, int startRow, int startColumn)
{
    if (startColumn < 0 || startRow < 0 || startColumn > n - 1 || startRow > m - 1)
    {
        return 1;
    }
    else
        return 0;
}
// int findPaths(int m, int n, int maxMove, int startRow, int startColumn, int moves)
// {
//     // base case
//     if (checkBoundary(m, n, maxMove, startRow, startColumn) && moves <= maxMove)
//     {
//         return 1;
//     }
//     if (moves == maxMove)
//     {
//         return checkBoundary(m, n, maxMove, startRow, startColumn) ? 1 : 0;
//     }

//     // rec
//     int left = findPaths(m, n, maxMove, startRow, startColumn - 1, moves + 1);
//     // cout << left << endl;
//     int up = findPaths(m, n, maxMove, startRow - 1, startColumn, moves + 1);
//     int down = findPaths(m, n, maxMove, startRow + 1, startColumn, moves + 1);
//     int right = findPaths(m, n, maxMove, startRow, startColumn + 1, moves + 1);
//     return left + right + up + down;
// }
int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    // base case
    if (checkBoundary(m, n, maxMove, startRow, startColumn) && maxMove > 0)
    {
        return 1;
    }
    if (maxMove == 0)
    {
        return checkBoundary(m, n, maxMove, startRow, startColumn) ? 1 : 0;
    }

    // rec
    int left = findPaths(m, n, maxMove - 1, startRow, startColumn - 1);
    // cout << left << endl;
    int up = findPaths(m, n, maxMove - 1, startRow - 1, startColumn);
    int down = findPaths(m, n, maxMove - 1, startRow + 1, startColumn);
    int right = findPaths(m, n, maxMove - 1, startRow, startColumn + 1);
    return left + right + up + down;
}
int main()
{
    int m = 2;
    int n = 2;
    int startRow = 0;
    int startColumn = 0;
    int maxMove = 2;
    cout << findPaths(m, n, maxMove, startRow, startColumn);
}