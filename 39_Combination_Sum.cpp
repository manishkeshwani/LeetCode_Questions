/*


39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

https://leetcode.com/problems/combination-sum/

*/

class Solution {

private:
    void helper(int idx, vector<int>& candidates, int target, vector<vector<int>> &ans ,int n , vector<int>ds){
        if(idx==n){
            if(target == 0){
                ans.push_back(ds);
                return;
            }
            else{return;}
        }

        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            helper(idx,candidates,target-candidates[idx],ans,n,ds);
            ds.pop_back();
        }
        helper(idx+1,candidates,target,ans,n,ds);

    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        int n = candidates.size();
        helper(0,candidates,target,ans,n,{});
        return ans;        
    }
};