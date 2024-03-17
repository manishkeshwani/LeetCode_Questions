/*

40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

 

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]


https://leetcode.com/problems/combination-sum-ii/
*/


class Solution {

private:
    void helper(int idx, vector<int>& candidates, int target, vector<vector<int>> &ans ,int n , vector<int>ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = idx ; i<n ; i++){
            if(i>idx && candidates[i]==candidates[i-1])continue;
            if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                helper(i+1,candidates,target-candidates[i],ans,n,ds);
                ds.pop_back();
            }
        }

    }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        int n = candidates.size();
        helper(0,candidates,target,ans,n,{});
        return ans;   
        
    }
};