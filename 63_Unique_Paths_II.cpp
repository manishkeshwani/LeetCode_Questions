/*

63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.
 
Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

https://leetcode.com/problems/unique-paths-ii/?source=submission-noac

*/

class Solution {
public:
int route(vector<vector<int>>& obstacleGrid, int row, int col,int n, int m, vector<vector<long long>>&dp){
    if(row==n-1 && col==m-1) return 1;
    if(row>=n || col>=m || obstacleGrid[row][col]==1)return 0;

    if(dp[row][col] != -1)return dp[row][col];
    dp[row][col] = (long long)route(obstacleGrid,row+1,col,n,m,dp) + (long long)route(obstacleGrid,row,col+1,n,m,dp);
    return dp[row][col];
}

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size(); 
        if(obstacleGrid[n-1][m-1]==1)
        return 0;
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        return route(obstacleGrid,0,0,n,m,dp);
    }
};