/*


90. Subsets II
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

https://leetcode.com/problems/subsets-ii/

*/

class Solution {
public:

    void helper(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int i = idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1])continue;
                temp.push_back(nums[i]);
                helper(i+1,nums,temp,ans);
                temp.pop_back();
            
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,nums,temp,ans);
        return ans;

    }
};