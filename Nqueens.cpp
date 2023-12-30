// Nqueens.cpp
#include<iostream>
using namespace std;

bool kyasafehPutKarna(int board[][100], int row, int col, int n) {
    // Check the current row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check left below diagonal
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool nQueen(int board[][100], int col, int n) {
    if (col == n) {
        // Print the board where queens are placed
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] == 1 ? cout << "Q " : cout << "_ ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    for (int row = 0; row < n; ++row) {
        if (kyasafehPutKarna(board, row, col, n)) {
            board[row][col] = 1;
            if (nQueen(board, col + 1, n)) {
                // If a solution is found, continue to find more solutions
                // Comment the following line if you only want one solution
                continue;
            }
            // Backtrack
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[100][100] = {0};
    int n;
    cin >> n;
    nQueen(board, 0, n);
    return 0;
}
