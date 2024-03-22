/*

46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

https://leetcode.com/problems/permutations/
*/


class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<vector<int>>&ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx ;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            helper(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        helper(0,nums,ans);      
        return ans;
    }
};