/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]


https://leetcode.com/problems/generate-parentheses/
*/

class Solution {

private:
void backtrack(vector<string> &res , string curr ,int left, int right ,int n){

    if(curr.size() == 2*n){
        res.push_back(curr);
        return;
    }
    if(left<n){
        backtrack(res,curr+'(',left+1,right,n);        
    }
    if(right<left){
        backtrack(res,curr+')',left,right+1,n);
    }
}
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        backtrack(res,"",0,0,n);

        return res;

        
    }
};