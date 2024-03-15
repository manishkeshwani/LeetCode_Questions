/*

930. Binary Subarrays With Sum
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array. 

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4

https://leetcode.com/problems/binary-subarrays-with-sum/
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        mpp[0]++;
        int ans=0;
        int sum=0;
        for(int i = 0; i<nums.size() ; i++){
            sum += nums[i];
            int rem = sum - goal;
            ans += mpp[rem];
            mpp[sum]++;          
        }

        return ans;
    }
};