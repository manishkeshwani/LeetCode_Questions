/*
525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
 
Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.


Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mpp;
        int len = 0;
        for(int i=0 ;i<n;i++){
            sum += (nums[i]==0)? -1:1;
            if(sum == 0) len = max(len,i+1);
            else if(mpp.find(sum) != mpp.end()) len = max(len,i-mpp[sum]);
            else mpp[sum]=i;
        }

        return len;
        
    }
};