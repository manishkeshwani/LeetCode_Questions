/*

52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1
 

Constraints:
1 <= n <= 9


https://leetcode.com/problems/n-queens-ii/
*/

class Solution {

    public:
    int solveNQueen(int col,int n,int &cnt, vector<string> &board, vector<int> &LeftRow, vector<int> &LowerDiagonal ,vector<int> &UpperDiagonal){
        if(col==n){
            return 1;
        }

        for(int row = 0 ; row<n ; row++){
            if(!LeftRow[row] && !LowerDiagonal[row+col] && !UpperDiagonal[n-1+col-row]){
                LeftRow[row]=1;
                LowerDiagonal[row+col]=1;
                UpperDiagonal[n-1+col-row]=1;
                board[row][col] = 'Q';
                cnt+=solveNQueen(col+1,n,cnt,board,LeftRow,LowerDiagonal,UpperDiagonal);
                board[row][col] = '.';
                LeftRow[row]=0;
                LowerDiagonal[row+col]=0;
                UpperDiagonal[n-1+col-row]=0;
            }
        }
        return 0;
    }

    int totalNQueens(int n) {

        int cnt = 0;;
        vector<string>board(n);
        vector<int>LeftRow(n,0);
        vector<int>LowerDiagonal(2*n-1,0);
        vector<int>UpperDiagonal(2*n-1,0);
        string s(n,'.');
        for(int i=0 ; i<n ; i++)board[i]=s;
        solveNQueen(0,n,cnt,board,LeftRow,LowerDiagonal,UpperDiagonal);
        return cnt;
        
    }
};