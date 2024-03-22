/*

51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 
Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

https://leetcode.com/problems/n-queens/

*/

class Solution {
public:
    void solveNQueen(int col,int n,vector<vector<string>> &ans, vector<string> &board , vector<int> &LeftRow, vector<int> &LowerDiagonal, vector<int> &UpperDiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row<n ; row++){
            if(!LeftRow[row] && !LowerDiagonal[row+col] && !UpperDiagonal[n-1+col-row]){
                LeftRow[row]=1;
                LowerDiagonal[row+col]=1;
                UpperDiagonal[n-1+col-row]=1;
                board[row][col] = 'Q';
                solveNQueen(col+1,n,ans,board,LeftRow,LowerDiagonal,UpperDiagonal);
                board[row][col] = '.';
                LeftRow[row]=0;
                LowerDiagonal[row+col]=0;
                UpperDiagonal[n-1+col-row]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++)board[i]=s;

        vector<int>LeftRow(n,0);
        vector<int>LowerDiagonal(2*n-1,0);
        vector<int>UpperDiagonal(2*n-1,0);

        solveNQueen(0,n,ans,board,LeftRow,LowerDiagonal,UpperDiagonal);
        return ans;
        
    }
};