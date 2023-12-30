#include <iostream>
#include <vector>
#include <string>

void solve(int col, std::vector<std::string>& board, std::vector<int>& leftRow,
           std::vector<int>& upperDiagonal, std::vector<int>& lowerDiagonal,
           std::vector<std::vector<std::string>>& ans, int n) {
    // base case
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; ++row) {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<std::vector<std::string>> ans;
    std::vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
    return ans;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    auto solutions = solveNQueens(n);

    // Display the solutions
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
