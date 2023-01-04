#include <bits/stdc++.h>
using namespace std;
// To store values of Sudoku while input
int board[9][9];

// Check function which determines whether position is valid or not
bool checkval(int row, int col, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == value)
        {
            return false;
        }
        if (board[i][col] == value)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
        {
        return false;
        }
    }
    return true;
}

bool recursion()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {                                 // Condition for Solving for empty space only
            if (board[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                  if (checkval(i, j, val))
                  {
                      board[i][j] = val;
                                               //recursion call
                      bool ans = recursion();
                      if (ans)
                      {
                         return true;
                      }
                      else
                      {
                           board[i][j] = 0;        //backtrack
                      }
                  }
                  return false;
            }
        }       
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //"Input value of sudoku in 9*9 matrix form for empty cell put 0" << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int temp;cin>>temp;
            board[i][j]=temp;
        }
    }
       // Recursion call
    bool ans = recursion();
       // Condition
    if (ans)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
               cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No Possible solution";
    }
}
