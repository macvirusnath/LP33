#include <iostream>
#include <vector>
using namespace std;
void printboard(vector<vector<int>> &board)
{
    for (auto it : board)
    {
        for (auto cell : it)
        {
            cout << (cell == 1 ? "Q" : "-") << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    // checking for columns
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1){
            return false;
        }
    }
    // cheking for upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1){
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; j++, i--)
    {
        if (board[i][j] == 1){
            return false;
        }
    }
    return true;
}
void solveNqueen(vector<vector<int>> &board, int row, int n)
{
    if (row == n)
    {
        printboard(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            solveNqueen(board, row + 1, n);
            board[row][col] = 0;
        }
    }
}
int main()
{
    int n;
    cout << "enter the no of queens" << endl;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNqueen(board, 0, n);

    return 0;
}